%{
	#include "symboltable.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();
    SymbolTableList* symbol_table_stack;
%}

/* YYSTYPE union */
%union{
    char char_val;
	int int_val;
	double double_val;
	char* str_val;
    char* str_val_id;
	SymbolTableList* symtablist;
}

/* token definition */
%token<int_val> CHAR INT FLOAT DOUBLE IF ELSE WHILE FOR CONTINUE BREAK VOID RETURN
%token<int_val> ADDOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP
%token<int_val> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN REFER
%token <str_val_id>   ID
%token <int_val>       ICONST
%token <double_val>    FCONST
%token <char_val>      CCONST
%token <str_val>       STRING

/* precedencies and associativities */
%left LPAREN RPAREN LBRACK RBRACK
%right NOTOP INCR REFER
%left MULOP DIVOP
%left ADDOP
%left RELOP
%left EQUOP
%left OROP
%left ANDOP
%right ASSIGN
%left COMMA


%start program

/* expression rules */

%%

program: functions {printf("empezando programa\n");} ;

/* declarations */
declarations: declarations declaration | declaration;

declaration: type names SEMI ;
// int x,y[100],*xd;
type: INT | CHAR | FLOAT | DOUBLE | VOID ;

names: names COMMA variable | names COMMA init | new_variable | init ;

new_variable: ID {
        printf("new variable\n");
        if(find_word_on_symboltablelist(symbol_table_stack,$1) == NULL){
            printf("new variable not on top list\n");
            insert_word_on_top(symbol_table_stack,$1);
        }
        else{
            printf("Error: Creo una variable iniciada xd: %s\n",$1);

        }
    }
    |
    pointer ID
    {
        insert_word_on_top(symbol_table_stack,$2);
    }
    |
    ID array {
        insert_word_on_top(symbol_table_stack,$1);
    }
;

variable: ID {
        if(find_word_on_symboltablelist(symbol_table_stack,$1) == NULL){
            printf("Error: Uso una variable no iniciada %s\n",$1);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
    | pointer ID | ID array ;
pointer: pointer MULOP | MULOP ;

array: array LBRACK expression RBRACK | LBRACK expression RBRACK ;

constant: ICONST | FCONST | CCONST ;


init: var_init | array_init ;

var_init : ID ASSIGN ICONST{
        if(find_word_on_symboltablelist(symbol_table_stack,$1) == NULL){
            insert_word_with_value_on_top(symbol_table_stack,$1,$3);
        }
        else{
            printf("Error: Creo una variable iniciada xd: %s\n",$1);

        }
    }

array_init: ID array ASSIGN LBRACE values RBRACE {
        insert_word_on_top(symbol_table_stack,$1);
    };

values: values COMMA constant | constant ;

/* statements */
statements: statements statement | statement ;

statement:
	if_statement | for_statement | while_statement | assigment SEMI |
	CONTINUE SEMI | BREAK SEMI | function_call SEMI | ID INCR SEMI | INCR ID SEMI
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

for_statement: FOR LPAREN assigment SEMI expression SEMI expression RPAREN tail {
    insert_new_symboltable_on_list(symbol_table_stack);
};

while_statement: WHILE LPAREN expression RPAREN tail {
    insert_new_symboltable_on_list(symbol_table_stack);
};

tail: LBRACE statements endtail ;

endtail: RBRACE {
    printf("voy a hacer pop endtail\n");
    SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
    print_symbol_table(st);
};

expression:
    expression ADDOP expression |
    expression MULOP expression |
    expression DIVOP expression |
    ID INCR {
        if (find_word_on_symboltablelist(symbol_table_stack, $1) == NULL) {
            printf("Error: Variable no declarada en la línea %d\n", lineno);
        }
    }|
    INCR ID {        if (find_word_on_symboltablelist(symbol_table_stack, $2) == NULL) {
            printf("Error: Variable no declarada en la línea %d\n", lineno);
        }
    }|
    expression OROP expression |
    expression ANDOP expression |
    NOTOP expression |
    expression EQUOP expression |
    expression RELOP expression |
    LPAREN expression RPAREN |
    var_ref |
    sign constant |
    function_call
;

sign: ADDOP | /* empty */ ; 

assigment: var_ref ASSIGN expression ;

var_ref  : variable | REFER variable ; 

function_call: ID LPAREN call_params RPAREN;

call_params: call_param | STRING | /* empty */

call_param : call_param COMMA expression | expression ; 

/* functions */
//functions_optional: functions | /* empty */ ;

functions: functions function | function  ;

function: function_head function_tail { 
    printf("function\n");
    insert_new_symboltable_on_list(symbol_table_stack);
} ;
		
function_head: return_type ID LPAREN parameters_optional RPAREN {
    printf("HOlaaaaa funcction head");};

return_type: type {
    printf("type\n");
}| type pointer 
    {printf("typepointer\n");}
;

parameters_optional: parameters {
    printf("parameters");
    }
    | /* empty */ {printf("parametersempty\n");} ;

parameters: parameters COMMA parameter {
    printf("parameters comma parameter\n");
    }
    | parameter {printf("parameter on parameters\n");};

parameter : type new_variable ;

function_tail: LBRACE declarations_optional statements_optional return_optional endtail ;

declarations_optional: declarations | /* empty */ ;

statements_optional: statements | /* empty */ ;

return_optional: RETURN expression SEMI | /* empty */;

%%


void yyerror (const char *s) {
    fprintf(stderr, "Syntax error  %s\n", s);
    exit(1);
}
/*
int parse_xd (char* file){
	symbol_table_stack = create_symboltable_list();
    SymbolTable* global_table = create_symbol_table();
    insert_symboltable_on_list(symbol_table_stack, global_table);
    yyin = fopen(file, "r");
    if (!yyin) {
        perror(file);
        return 1;
    }

    int flag = yyparse();
    printf("Parsing finished!\n");

    SymbolTable* global = pop_symboltable_stack(symbol_table_stack);
    printf("Global Symbol Table:\n");
    print_symbol_table(global);

    return flag;
}*/

int main (int argc, char *argv[]){
    symbol_table_stack = create_symboltable_list();
    insert_new_symboltable_on_list(symbol_table_stack);
	// parsing
    printf("primero\n");
	int flag;
	yyin = fopen(argv[1], "r");
    printf("yyin leido\n");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!");
	
	// symbol table dump
	//yyout = fopen("symtab_dump.out", "w");
	//symtab_dump(yyout);
	//fclose(yyout);
	
	return flag;
}
/*
int main (int argc, char *argv[]) {
    symbol_table_stack = create_symboltable_list();
    SymbolTable* global_table = create_symbol_table();
    insert_symboltable_on_list(symbol_table_stack, global_table);

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    }

    int flag = yyparse();
    printf("Parsing finished!\n");

    SymbolTable* global = pop_symboltable_stack(symbol_table_stack);
    printf("Global Symbol Table:\n");
    print_symbol_table(global);

    return flag;
}
*/