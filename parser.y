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
    Sym
}

/* token definition */
%token<value> CHAR INT FLOAT DOUBLE IF ELSE WHILE FOR CONTINUE BREAK VOID RETURN
%token<value> ADDOP MINUSOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP
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

%type <value> var_init
%type <value> constant
%type <value> expression
%type <value> function_call
%type <value> var_ref
%type <value> variable
%type <value> pointer
%type <value> incr_id

%start program

/* expression rules */

%%

program: functions     ; 


/* functions */
//functions_optional: functions | /* empty */ ;

functions: functions function | function  ;

function: function_head function_tail { 
    insert_new_symboltable_on_list(symbol_table_stack);
} ;
		
function_head: return_type ID LPAREN parameters_optional RPAREN;

return_type: type | type pointer 
;

parameters_optional: parameters 
    | /* empty */  ;

parameters: parameters COMMA parameter 
    | parameter ;

parameter : type new_variable ;

function_tail: lbrace_token statements_optional return_optional endtail ;

// declarations_optional: declarations | /* empty */ ;

statements_optional: statements | /* empty */ ;

return_optional: RETURN expression semi_token | RETURN semi_token | /* empty */;

;
// int x,y[100],*xd;

/* statements */
statements: statements statement | statement ;

statement:
	if_statement | for_statement | while_statement | assigment semi_token |
	CONTINUE semi_token | BREAK semi_token | function_call semi_token | incr_id semi_token | declaration
;

if_statement:
	IF LPAREN expression RPAREN tail else_if optional_else |
	IF LPAREN expression RPAREN tail optional_else
;

else_if: 
	else_if ELSE IF LPAREN expression RPAREN tail |
	ELSE IF LPAREN expression RPAREN tail
;

optional_else: ELSE tail | /* empty */ ;

for_statement: inicio_for declaration  optional_expression semi_token optional_expression RPAREN tail  
    |
    inicio_for semi_token optional_expression semi_token optional_expression RPAREN tail
;

inicio_for : FOR LPAREN {
        insert_new_symboltable_on_list(symbol_table_stack);
};


while_statement: inicio_while optional_expression RPAREN tail ;
 //| error {yyerror("Error en la declaración del while"); yyerrok;}

inicio_while : WHILE LPAREN {
        insert_new_symboltable_on_list(symbol_table_stack);
}
tail: lbrace_token optional_statements endtail //| error {yyerror("Falta de apertura de contexto -> {"); yyerrok;}
;

optional_statements : /*empty*/ |  statements

endtail: rbrace_token {
    //printf("voy a hacer pop endtail\n");
    SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
    print_symbol_table(st);
} //| error {yyerror("Falta de cierre de contexto -> }"); yyerrok;}

declaration: type names semi_token


type: INT | CHAR | FLOAT | DOUBLE | VOID //| error {yyerror("Falta de tipo"); yyerrok;}
;

names: names COMMA new_variable | names COMMA init | new_variable | init ;

new_variable: ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            insert_word_on_top(symbol_table_stack,$1.sval);
        }
        else{
            print_error_variable_redeclarada(($1.sval), lineno);
        }
    }
    |
    pointer ID
    {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$2.sval) == NULL){
            insert_word_on_top(symbol_table_stack,$2.sval);
        }
        else{
            print_error_variable_redeclarada(($2.sval), lineno);
        }
    }
    |
    ID array {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            insert_word_on_top(symbol_table_stack, ($1.sval));
        }
        else{
            print_error_variable_redeclarada (($1.sval), lineno);
        }
    }
;

variable: ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            print_error_variable_no_declarada(($1.sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
    | pointer ID {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            print_error_variable_no_declarada(($2.sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
    | ID array {
        if(find_word_on_all_symboltablelist(symbol_table_stack,$1.sval) == NULL){
            print_error_variable_no_declarada(($1.sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    };
pointer: pointer MULOP | MULOP ;

array: array LBRACK expression RBRACK | LBRACK expression RBRACK ;

constant: ICONST {Value new_value;
                new_value.ival = $1.ival;
                $$ = new_value;
                }
                | 
                FCONST 
                {Value new_value;
                new_value.ival = $1.ival;
                $$ = new_value;
                }
                | 
                CCONST ;


init: var_init  | array_init ;

var_init : ID ASSIGN expression{
        if( (find_word_on_start_symboltablelist(symbol_table_stack,$1.sval)) == NULL){
            insert_word_with_value_on_top(symbol_table_stack,$1.sval,$3.ival);
        }
        else{
            print_error_variable_redeclarada (($1.sval), lineno);
        }
    };
    

array_init: ID array ASSIGN lbrace_token values rbrace_token {
    };

values: values COMMA constant | constant ;


optional_expression : expression | /*empty*/;

expression:
    expression ADDOP expression |
    expression MINUSOP expression |
    expression MULOP expression |
    expression DIVOP expression |
    incr_id|
    expression OROP expression |
    expression ANDOP expression |
    NOTOP expression |
    expression EQUOP expression |
    expression RELOP expression |
    LPAREN expression RPAREN |
    var_ref |
    sign constant {$$ = $2;}|
    function_call
;


incr_id : ID INCR{
        if (find_word_on_all_symboltablelist(symbol_table_stack, $1.sval) == NULL) {
            print_error_variable_no_declarada (($1.sval), lineno);
        }
    }
        |
        INCR ID {
            if (find_word_on_all_symboltablelist(symbol_table_stack, $2.sval) == NULL) {
            print_error_variable_no_declarada (($2.sval), lineno);
        }
    }

sign: ADDOP | MINUSOP | /* empty */ ; 

assigment: var_ref ASSIGN expression;

var_ref  : variable | REFER variable ; 

function_call: ID LPAREN call_params RPAREN;

call_params: call_param | STRING | /* empty */

call_param : call_param COMMA expression | expression ; 

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

int main (int argc, char *argv[]){
    symbol_table_stack = create_symboltable_list();
    insert_new_symboltable_on_list(symbol_table_stack);
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("bye bye!\n");
	
	// symbol table dump
	//yyout = fopen("symtab_dump.out", "w");
	//symtab_dump(yyout);
	//fclose(yyout);
	
	return flag;
}