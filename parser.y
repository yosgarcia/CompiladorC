%{
    #include "symboltable.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    extern FILE *yyout;
    extern int lineno;
    extern int yylex();
    void yyerror();

    SymbolTableList* symbol_table_stack;
    int parse_xd (char* file);
%}

%union{
    char char_val;
    int int_val;
    double double_val;
    char* str_val;
}

%token<int_val> CHAR INT FLOAT DOUBLE IF ELSE WHILE FOR CONTINUE BREAK VOID RETURN
%token<int_val> ADDOP MULOP DIVOP INCR OROP ANDOP NOTOP EQUOP RELOP
%token<int_val> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN REFER
%token <str_val>   ID
%token <int_val>       CONST_INTEGER
%token <double_val>    FCONST
%token <char_val>      CCONST
%token <str_val>       STRING

%left ELSE
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

%%

program: declarations statements RETURN SEMI functions_optional ;

declarations: declarations declaration | declaration;

declaration: type names SEMI ;

type: INT | CHAR | FLOAT | DOUBLE | VOID ;

names: names COMMA variable | names COMMA init | variable | init ;

variable: ID { insert_word(symbol_table_stack->start, $1); } |
          pointer ID { insert_word(symbol_table_stack->start, $2); } |
          ID array { insert_word(symbol_table_stack->start, $1); }
;

pointer: pointer MULOP | MULOP ;

array: array LBRACK expression RBRACK | LBRACK expression RBRACK ;

init: var_init | array_init ;

var_init: ID ASSIGN CONST_INTEGER { insert_word_with_value(symbol_table_stack->start, $1, $3); }

array_init: ID array ASSIGN LBRACE values RBRACE { insert_word(symbol_table_stack->start, $1); }

values: values COMMA constant | constant ;

statements: statements statement | statement ;

statement: if_statement | for_statement | while_statement | assigment SEMI |
           CONTINUE SEMI | BREAK SEMI | function_call SEMI | ID INCR SEMI | INCR ID SEMI
;

if_statement: IF LPAREN expression RPAREN tail optional_else ;

optional_else: ELSE tail | /* empty */ ;

tail: LBRACE statements RBRACE ;

for_statement: FOR LPAREN assigment SEMI expression SEMI expression RPAREN tail ;

while_statement: WHILE LPAREN expression RPAREN tail ;

expression: expression ADDOP expression |
            expression MULOP expression |
            expression DIVOP expression |
            ID INCR |
            INCR ID |
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

constant: CONST_INTEGER | FCONST | CCONST ;

assigment: var_ref ASSIGN expression ;

var_ref: variable | REFER variable ;

function_call: ID LPAREN call_params RPAREN;

call_params: call_param | STRING | /* empty */

call_param: call_param COMMA expression | expression ;

functions_optional: functions | /* empty */ ;

functions: functions function | function ;

function: function_head function_tail ;
        
function_head: return_type ID LPAREN parameters_optional RPAREN ;

return_type: type | type pointer ;

parameters_optional: parameters | /* empty */ ;

parameters: parameters COMMA parameter | parameter ;

parameter: type variable ;

function_tail: LBRACE declarations_optional statements_optional return_optional RBRACE ;

declarations_optional: declarations | /* empty */ ;

statements_optional: statements | /* empty */ ;

return_optional: RETURN expression SEMI | /* empty */ ;

%%

void yyerror (const char *s) {
    fprintf(stderr, "Syntax error  %s\n", s);
    exit(1);
}

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