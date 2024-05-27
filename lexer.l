%option noyywrap
 
%{
    //noyywrap indica que solo se usara un archivo de input
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symboltable.h"
    #include "parser.tab.h"
    extern FILE *yyin; //File input
    extern FILE *yyout; //File output
    int lineno = 1; // initialize to 1
    void print_token(char *token_type); //Imprimir info del token
    void yyerror();
%}
 
%x ML_COMMENT 
 //multi line comment 
alpha       [a-zA-Z]
_alpha  [_a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
_alnum [_a-zA-Z0-9]
printableChar       [ -~]
 
ID          {_alpha}{_alnum}*
ICONST      "0"|[0-9]{digit}*
FCONST      "0"|{digit}*"."{digit}+
 // \'\\[nftrbv]\' son chars como '\t' o '\n' 
CCONST      (\'{printableChar}\')|(\'\\[nftrbv]\')
STRING      \"{printableChar}*\"
 
%%
 
"//".*        { printf("Eat up comment at line %d\n", lineno); } 

"/*"          { printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"    { printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+		
<ML_COMMENT>"*"			
<ML_COMMENT>"\n"    { lineno += 1; }


"char"|"CHAR"         { return CHAR; }
"int"|"INT"           { return INT; }
"float"|"FLOAT"       { return FLOAT; }
"double"|"DOUBLE"     { return DOUBLE; }
"if"|"IF"             { return IF; }
"else"|"ELSE"         { return ELSE; }
"while"|"WHILE"       { return WHILE; }
"for"|"FOR"           { return FOR; }
"continue"|"CONTINUE" { return CONTINUE; }
"break"|"BREAK"       { return BREAK; }
"void"|"VOID"         { return VOID; }
"return"|"RETURN"     { return RETURN; }


"+"|"-"             { return ADDOP; }
"*"                 { return MULOP; }
"/"                 { return DIVOP; }
"++"|"--"           { return INCR; }
"||"                { return OROP; }
"&&"                { return ANDOP; }
"!"                 { return NOTOP; }
"=="|"!="           { return EQUOP; }
">"|"<"|">="|"<="   { return RELOP; }


"("       { return LPAREN; }
")"       { return RPAREN; }
"]"       { return RBRACK; }
"["       { return LBRACK; }
"{"       { return LBRACE; }
"}"       { return RBRACE; }
";"       { return SEMI; }
"."       { return DOT; }
","       { return COMMA; }
"="       { return ASSIGN; }
"&"       { return REFER; }


{ID}    {
        // insert identifier into symbol table
        //insert(yytext, strlen(yytext), UNDEF, lineno);
        
        //insert_word_on_top(yylval.symtablist, yytext);
        //yylval.symtab_item = lookup(yytext);
        //yylval.str_val = malloc(yyleng * sizeof(char));
        //strcpy(yylval.str_val, yytext);
        yylval.str_val_id = malloc(yyleng * sizeof(char));
        strcpy(yylval.str_val_id, yytext);
        return ID;
        }
{ICONST}    { yylval.int_val   = atoi(yytext); return ICONST; }
{FCONST}    { yylval.double_val = atof(yytext); return FCONST; }
{CCONST}    { yylval.char_val  = yytext[0];    return CCONST; }
{STRING}    { yylval.str_val = malloc(yyleng * sizeof(char));
              strcpy(yylval.str_val, yytext);  return STRING; }

 
 
"\n"			{ lineno += 1; }
[ \t\r\f]+			/* eat up whitespace */
 
.				{ yyerror("Unrecognized character"); }

%%
 
void print_token(char *token_type){
    printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}
 /*
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}
*/
/*
int main(int argc, char *argv[]){
	// initialize symbol table
	init_hash_table();

	// open input file
	yyin = fopen(argv[1], "r");
	
	// lexical analysis
	yylex();
	fclose(yyin);
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);	
	
	return 0;
}
*/