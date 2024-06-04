%{
	#include "symboltable.c"
    #include "ast.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror(const char* s );
    void print_error_variable_redeclarada (char* name, int line);
    void print_error_variable_no_declarada (char* name, int line);
    SymbolTableList* symbol_table_stack;
    int yyerrstatus = 0; // Declaración de yyerrstatus
    struct NodeAST* root = NULL;
    int estoy_main = 0;

%}

/* YYSTYPE union */
%union{
    Value value;
    /*
    char char_val;
	int int_val;
	double double_val;
	char* str_val;
    */
    char* str_val_id;
	SymbolTableList* symtablist;
    struct NodeAST* node;
}

/* token definition */
%token<value> CHAR INT FLOAT DOUBLE IF ELSE WHILE FOR CONTINUE BREAK VOID RETURN
%token<value> ADDOP MINUSOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP DECR
%token<value> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN REFER
%token <value> ID
%token <value> ICONST FCONST CCONST STRING 

/* precedencies and associativities */
%left LPAREN RPAREN LBRACK RBRACK
%right NOTOP INCR REFER
%left MULOP DIVOP
%left ADDOP MINUSOP
%left RELOP
%left EQUOP
%left OROP
%left ANDOP
%right ASSIGN
%left COMMA

%type <node> var_init init  
%type <node> constant
%type <node> expression optional_expression
%type <node> function_call
%type <node> var_ref
%type <node> variable
%type <node> pointer
%type <node> incr_id
%type <node> program
%type <node> type
%type <node> assigment
%type <node> statement statements tail statements_optional optional_statements
%type <node> if_statement else_if optional_else
%type <node> for_statement while_statement
%type <node> functions function function_head function_tail
%type <node> return_optional
%type <node> parameters_optional parameters parameter
%type <node> return_type
%type <node> declaration
%type <node> names values
%type <node> new_variable
%type <node> sign 
%type <node> call_param
%type <node> call_params
%type <node> decr_id


%start program

/* expression rules */

%%

program:
    functions {
        root = create_ast_node(PROGRAM_NODE, "PROGRAM");
        add_child(root, $1);
    }
; 


/* functions */
//functions_optional: functions | /* empty */ ;

functions:
    functions function {
        $$ = create_ast_node(FUNCTIONS_NODE, "FUNCTIONS");
        add_child($$, $1);
        add_child($$, $2);
        }
    | function {
        $$ = $1;
    }

function: function_head function_tail {
    $$ = create_ast_node(FUNCTION_NODE, "FUNCTION"); 
    add_child($$, $1);
    add_child($$, $2);
    }
;

		
function_head:
    return_type ID LPAREN parameters_optional RPAREN {
        insert_new_symboltable_on_list(symbol_table_stack);
        $$ = create_ast_node(FUNCTION_HEAD_NODE, "FUNCTION_HEAD"); // Crear nodo de cabecera de función
        add_child($$, create_ast_node(TYPE_NODE, ($1->lexema))); // Añadir nodo de tipo como hijo
        add_child($$, create_ast_node(ID_NODE, ($2.sval))); // Añadir nodo de identificador como hijo
        //$$ = create_and_add_node(FUNCTION_HEAD_NODE, "FUNCTION_HEAD", NULL); // Crear nodo de cabecera de función
        //add_child($$, create_ast_node(TYPE_NODE, $1.lexema)); // Añadir nodo de tipo como hijo
        //add_child($$, create_ast_node(ID_NODE, $2)); // Añadir nodo de identificador como hijo
        //add_child($$, $4); // Añadir los parámetros (si los hay) como hijos
    }
;

return_type:
    type{
        $$ = create_ast_node(RETURN_TYPE_NODE, "RETURN_TYPE"); // Crear nodo de tipo de retorno
        add_child($$, create_ast_node(TYPE_NODE, $1->lexema)); // Añadir nodo de tipo como hijo
    }
    | type pointer ;

parameters_optional:
    parameters {
        $$ = $1;
    } | /* empty */ {
        $$ = NULL;
    }
;

parameters:
    parameters COMMA parameter {   
        add_child($1, $3); // Añadir nuevo parámetro a la lista de parámetros
        $$ = $1; // Devolver la lista de parámetros actualizada
    }
    | parameter {
    }
;

parameter:
    type new_variable {
        $$ = create_ast_node(PARAMETER_NODE, "PARAMETER"); // Crear nodo de parámetro
        add_child($$, create_ast_node(TYPE_NODE, $1->lexema)); // Añadir nodo de tipo como hijo
        add_child($$, $2); // Añadir nodo de identificador como hijo
    }
;

function_tail:
    lbrace_token statements_optional return_optional endtail_function {
        $$ = create_ast_node(FUNCTION_TAIL_NODE, "FUNCTION_TAIL"); // Crear nodo de cola de función
        add_child($$, $2); // Añadir las declaraciones y las instrucciones como hijos
        if ($3 != NULL) {
            add_child($$, $3); // Añadir el nodo de retorno (si lo hay) como hijo
        }
    }
;

statements_optional:
    statements {
        if (($1 != NULL)) {
            $$ = create_ast_node(STATEMENTS_NODE, "STATEMENTS"); // Crear nodo de instrucciones
            add_child($$, $1); // Añadir las instrucciones como hijo
        } else {
            $$ = NULL;
        }
    } | /* empty */ {
        $$ = NULL;
    }
;

return_optional:
    RETURN expression semi_token {
        $$ = create_ast_node(RETURN_NODE, "RETURN"); // Crear nodo de retorno
        add_child($$, $2); // Añadir la expresión como hijo
    }
    | RETURN semi_token {
        $$ = create_ast_node(RETURN_NODE, "RETURN"); // Crear nodo de retorno
    }
    | /* empty */ {
        $$ = NULL;
    }
;



/* statements */
statements:
    statements statement { 
        $$ = create_ast_node(STATEMENT_LIST_NODE, "STATEMENTS");
        add_child($$, $1);
        add_child($$, $2);
    } | statement
;

statement:
    if_statement {
        $$ = $1;
    } | for_statement{
        $$ = $1;
    } | while_statement{
        $$ = $1;
    } | assigment semi_token {
        $$ = $1;
    }| CONTINUE semi_token {
        $$ = create_ast_node(CONTINUE_NODE,"");
    } | BREAK semi_token {
        $$ = create_ast_node(BREAK_NODE,"");
    } | function_call semi_token{
        $$ = $1;
    } | incr_id semi_token{
        $$ = create_ast_node(INCR_ID_NODE_NODE,"INCR_ID_NODE_NODE");
        add_child($$,$1);
    } | decr_id semi_token{
        $$ = create_ast_node(DECR_ID_NODE_NODE,"DECR_ID_NODE_NODE");
        add_child($$,$1);
    } | declaration {
        $$ = $1;
    }
;

if_statement:
	IF LPAREN expression RPAREN tail else_if optional_else {
        $$ = create_ast_node(IF_STATEMENT_NODE, "IF_STATEMENT_NODE");
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $6);
        if($7 != NULL){
            add_child($$, $7);
        }
    }
    |
	IF LPAREN expression RPAREN tail optional_else {
        
        $$ = create_ast_node(IF_STATEMENT_NODE, "IF_STATEMENT"); 
        add_child($$, $3); 
        add_child($$, $5);  
        if ($6 != NULL) {
            add_child($$, $6); 
        }
    }
;

else_if:
	else_if ELSE IF LPAREN expression RPAREN tail {
        $$ = create_ast_node(ELSE_IF_NODE, "ELSE_IF");
        add_child($$, $5);
        add_child($$, $7); 
    }
    |
	ELSE IF LPAREN expression RPAREN tail {
        $$ = create_ast_node(ELSE_IF_NODE, "ELSE_IF");
        add_child($$, $4);
        add_child($$, $6);
    }
;

optional_else:
    ELSE tail {
        $$ = create_ast_node(ELSE_NODE, "ELSE");
        add_child($$, $2);
    }
    |
    /* empty */ {
        $$ = NULL;
    }
;

for_statement:
    inicio_for declaration  optional_expression semi_token optional_expression RPAREN tail {
        $$ = create_ast_node(FOR_STATEMENT_NODE, "FOR_DECLARATION_STATEMENT");
        add_child($$, $2);
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $7);
    }
    |
    inicio_for semi_token optional_expression semi_token optional_expression RPAREN tail {
        $$ = create_ast_node(FOR_STATEMENT_NODE, "FOR_STATEMENT");
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $7);
    }
;

inicio_for:
    FOR LPAREN {
        insert_new_symboltable_on_list(symbol_table_stack);
    }
;


while_statement:
    inicio_while optional_expression RPAREN tail {
        $$ = create_ast_node(WHILE_STATEMENT_NODE, "WHILE_STATEMENT");
        add_child($$, $2);
        add_child($$, $4);
    }
;


inicio_while:
    WHILE LPAREN {
        insert_new_symboltable_on_list(symbol_table_stack);
    }
;

tail:
    lbrace_token optional_statements end_tail {
        $$ = create_ast_node(TAIL_NODE, "TAIL");
        if ($2 != NULL) {
            add_child($$, $2); // Añadir las instrucciones opcionales como hijo
        }
    }
;

optional_statements:
    /* empty */ {
        $$ = NULL; // Nodo vacío si no hay instrucciones
    }
    |
    statements {
        $$ = $1; // Devolver el nodo de instrucciones
    }
;


endtail_function:
    rbrace_token {
        SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
        print_symbol_table(st);
        if(estoy_main){
            estoy_main = 0; //Salir del main
        }
    }
;

end_tail:
    rbrace_token {
        SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
        print_symbol_table(st);
    }
;


declaration:
    type names semi_token {
        $$ = create_ast_node(DECLARATION_NODE, "DECLARATION"); // Crear nodo de declaración
        add_child($$, $1); // Añadir el tipo como hijo
        add_child($$, $2); // Añadir los nombres como hijo
    }
;


type:
    INT {
        $$ = create_ast_node(TYPE_NODE, "INT");
    }
    | CHAR {
        $$ = create_ast_node(TYPE_NODE, "CHAR");
    }
    | FLOAT {
        $$ = create_ast_node(TYPE_NODE, "FLOAT");
    }
    | DOUBLE {
        $$ = create_ast_node(TYPE_NODE, "DOUBLE");
    }
    | VOID {
        $$ = create_ast_node(TYPE_NODE, "VOID");
    }
;

names:
    names COMMA new_variable {
        $$ = $1;
        add_child($$, $3); // Añadir la nueva variable como hijo
    }
    | names COMMA init {
        $$ = $1;
        add_child($$, $3); // Añadir la inicialización como hijo
    }
    | new_variable {
        $$ = create_ast_node(NAMES_NODE, "NAMES"); // Crear nodo de nombres
        add_child($$, $1); // Añadir la nueva variable como hijo
    }
    | init {
        $$ = create_ast_node(NAMES_NODE, "NAMES"); // Crear nodo de nombres
        add_child($$, $1); // Añadir la inicialización como hijo
    }
;

new_variable:
    ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            insert_word_on_top(symbol_table_stack,$1.sval);
            $$ = create_ast_node(VARIABLE_NODE, $1.sval);
        }
        else{
            print_error_variable_redeclarada(($1.sval), lineno);
            $$ = NULL;
        }
    }
    | pointer ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$2.sval) == NULL){
            insert_word_on_top(symbol_table_stack,$2.sval);
            $$ = create_ast_node(VARIABLE_NODE, $2.sval);
        }
        else{
            print_error_variable_redeclarada(($2.sval), lineno);
            $$ = NULL;
        }
    }
    | ID array {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            insert_word_on_top(symbol_table_stack, ($1.sval));
            $$ = create_ast_node(VARIABLE_NODE, $1.sval);
        }
        else{
            print_error_variable_redeclarada (($1.sval), lineno);
            $$ = NULL;
        }
    }
;

variable: ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            print_error_variable_no_declarada(($1.sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
            $$ = NULL;
        } else{
            $$ = create_ast_node(VARIABLE_NODE, $1.sval);
        }
    }
    | pointer ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$2.sval) == NULL){
            print_error_variable_no_declarada(($2.sval), lineno);
            $$ = NULL;
            //insert_word_on_top(symbol_table_stack,yytext);
        } else{
            $$ = create_ast_node(VARIABLE_NODE, $2.sval);
        }
    }
    | ID array {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            print_error_variable_no_declarada(($1.sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
            $$ = NULL;
        } else{
            $$ = create_ast_node(VARIABLE_NODE, $1.sval);
        }
    }
;
    
pointer:
    pointer MULOP {
        $$ = $1;
    }
    | MULOP {
        $$ = create_ast_node(POINTER_NODE, "*");
    }
;

array:
    array LBRACK expression RBRACK | LBRACK expression RBRACK ;

constant:
    ICONST {               
        $$ = create_ast_node(CONSTANT_NODE, intToStr($1.ival));
    }
    | FCONST {
        $$ = NULL;
    }
    | CCONST {
        $$ = NULL;
    }
;


init:
    var_init {
        $$ = $1;
    } | array_init {
        $$ = NULL;
    }
;

var_init:
    ID ASSIGN expression{
        if( (find_word_on_start_symboltablelist(symbol_table_stack,$1.sval)) == NULL){
            
            insert_word_on_top(symbol_table_stack,$1.sval);
            $$ = create_ast_node(VAR_INIT_NODE, "VAR_INIT");
            add_child($$, create_ast_node(ID_NODE, $1.sval));
            add_child($$, $3);
        }
        else{
            print_error_variable_redeclarada (($1.sval), lineno);
            $$ = NULL;
        }
    }
;

array_init: ID array ASSIGN lbrace_token values rbrace_token

values:
    values COMMA constant {
        $$ = $1;
        add_child($$, $3);
    } | constant {
        $$ = create_ast_node(VALUES_NODE, "VALUES");
        add_child($$, $1);
    }
;

optional_expression:
    expression {
        $$ = $1;
    } | /* empty */ {
        $$ = NULL;
    }
;

expression:
    expression ADDOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "ADDOP");
        add_child($$, $1);
        add_child($$, $3);
    } | expression MINUSOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "MINUSOP");
        add_child($$, $1);
        add_child($$, $3);
    } | expression MULOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "MULOP");
        add_child($$, $1);
        add_child($$, $3);
    } | expression DIVOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "DIVOP");
        add_child($$, $1);
        add_child($$, $3);
    } | incr_id {
        $$ = create_ast_node(INCR_ID_NODE_NODE, "INCR_ID_NODE_NODE");
        add_child($$,$1);
    } | decr_id {
        $$ = create_ast_node(DECR_ID_NODE_NODE, "DECR_ID_NODE_NODE");
        add_child($$,$1);
    } | expression OROP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "OROP");
        add_child($$, $1);
        add_child($$, $3);
    } | expression ANDOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "ANDOP");
        add_child($$, $1);
        add_child($$, $3);
    } | NOTOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "NOTOP");
        add_child($$, $2);
    } | expression EQUOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "EQUOP");
        add_child($$, $1);
        add_child($$, $3);
    } | expression RELOP expression {
        $$ = create_ast_node(EXPRESSION_NODE, "RELOP");
        add_child($$, $1);
        add_child($$, $3);
    } | LPAREN expression RPAREN {
        $$ = $2;
    } | var_ref {
        $$ = $1;
    } | sign constant {
        $$ = $2;
    } | function_call {
        $$ = $1;
    }
;


incr_id:
    ID INCR{
        if (find_word_on_all_symboltablelist(symbol_table_stack, $1.sval) == NULL) {
            print_error_variable_no_declarada (($1.sval), lineno);
            $$ = NULL;
        } else{
            //
            $$ = create_ast_node(ID_INCR_NODE, $1.sval);
        }
    }
    | INCR ID {
        if (find_word_on_all_symboltablelist(symbol_table_stack, $2.sval) == NULL) {
            print_error_variable_no_declarada (($2.sval), lineno);
            $$ = NULL;
        } else{
            $$ = create_ast_node(INCR_ID_NODE, $2.sval);
        }
    }
;

decr_id:
    ID DECR{
        if (find_word_on_all_symboltablelist(symbol_table_stack, $1.sval) == NULL) {
            print_error_variable_no_declarada (($1.sval), lineno);
            $$ = NULL;
        } else{
            //
            $$ = create_ast_node(ID_DECR_NODE, $1.sval);
        }
    }
    | DECR ID {
        if (find_word_on_all_symboltablelist(symbol_table_stack, $2.sval) == NULL) {
            print_error_variable_no_declarada (($2.sval), lineno);
            $$ = NULL;
        } else{
            $$ = create_ast_node(DECR_ID_NODE, $2.sval);
        }
    }
;

sign:
    ADDOP {
        $$ = create_ast_node(ADD_NODE, "");
    }
    | MINUSOP {
        $$ = create_ast_node(MINUS_NODE,"");
    }
    | /* empty */ {
        $$ = NULL;
    }
;

assigment:
    var_ref ASSIGN expression {
        $$ = create_ast_node(ASSIGNMENT_NODE, "ASSIGNMENT");
        add_child($$, $1);
        add_child($$, $3);
    }
;

var_ref:
    variable {
        $$ = $1;
    }
    | REFER variable {
    /*
    $$ = create_ast_node(REFERENCE_NODE, "REFERENCE", NULL); // Crear nodo de referencia
    add_child($$, $2); // Añadir la variable como hijo
    */
    }
;

function_call:
    ID LPAREN call_params RPAREN {
        $$ = create_ast_node(FUNCTION_CALL_NODE, $1.sval); // Crear nodo de llamada a función
        if ($3 != NULL) {
            add_child($$, $3); // Añadir los parámetros de llamada como hijos
        }
    }
;

call_params:
    call_param{
        $$ = $1;
    } | STRING {
        $$ = create_ast_node(STRING_NODE, $1.sval);
    }| /* empty */{
        $$ = NULL;
    };

call_param:
    call_param COMMA expression {
        $$ = create_and_add_node(CALL_PARAM_NODE,"CALL_PARAM_NODE",$3);
        add_child($$, $1);
    }| expression {
        $$ = create_ast_node(CALL_PARAM_NODE, "CALL_PARAM_NODE");
        add_child($$, $1);
    };

semi_token : SEMI | error {yyerror("Falta ; al final de la instruccion"); yyerrok;}
rbrace_token: RBRACE | error {yyerror("Falta } al final"); yyerrok;}
lbrace_token : LBRACE | error {yyerror("Esperaba un {"); yyerrok;}

%%

void print_error_variable_redeclarada (char* name, int line){
    printf("Error: Variable %s redeclarada en la línea %d\n", name, line);
}

void print_error_variable_no_declarada(char* name, int line){
    printf("Error: Variable %s no declarada en la línea %d\n", name, line);
}

void yyerror (const char *s) {
    fprintf(stderr, "Syntax error  en la linea %d: %s\n", lineno, s);
    //yyerrok(); // Permite que el análisis continúe después de un error
    //exit(1);
}


/*
bison -d parser.y
gcc -o programa parser.tab.c lex.yy.c
gcc -o programa ast.c parser.tab.c lex.yy.c
./programa test2.c
*/
int main (int argc, char *argv[]){
    symbol_table_stack = create_symboltable_list();
    insert_new_symboltable_on_list(symbol_table_stack);
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
    print_AST_tree(root, 0);
	printf("bye bye!\n");
	
	// symbol table dump
	//yyout = fopen("symtab_dump.out", "w");
	//symtab_dump(yyout);
	//fclose(yyout);
	
	return flag;
}