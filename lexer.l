%{
#include "symboltable.h"
#include "parser.tab.h"
%}

%option noyywrap

%%
"+"         { printf("xd\n"); return ADDOP; }
"*"         { printf("*\n"); return MULOP; }
"/"         { return DIVOP; }
"++"        { return INCR; }
"||"        { return OROP; }
"&&"        { return ANDOP; }
"!"         { return NOTOP; }
"=="        { return EQUOP; }
"!="        { return EQUOP; }
"<"         { return RELOP; }
">"         { return RELOP; }
"<="        { return RELOP; }
">="        { return RELOP; }
"("         {printf("parentesis (\n"); return LPAREN; }
")"         { return RPAREN; }
"["         { return LBRACK; }
"]"         { return RBRACK; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMI; }
"."         { return DOT; }
","         { return COMMA; }
"="         {printf("equal =\n"); return ASSIGN; }
"&"         { return REFER; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"continue"  { return CONTINUE; }
"break"     { return BREAK; }
"void"      { return VOID; }
"return"    { return RETURN; }
"int"       {printf("INT\n"); return INT; }
"char"      { return CHAR; }
"float"     { return FLOAT; }
"double"    { return DOUBLE; }
[0-9]+      { yylval.int_val = atoi(yytext); return CONST_INTEGER; }
[0-9]+"."[0-9]* { yylval.double_val = atof(yytext); return FCONST; }
\'[^\']\'   { yylval.char_val = yytext[1]; return CCONST; }
\"[^\"]*\"  { yylval.str_val = strdup(yytext); return STRING; }
[a-zA-Z_][a-zA-Z0-9_]* { /*yylval.symtab_item = lookup_symbol(yytext);*/printf("IDXd\n"); return ID; }
[ \t\n\r]+  ;  // Ignorar espacios en blanco
.           { fprintf(stderr, "Caracter no reconocido: %s\n", yytext); }
%%
/*
int yywrap() {
    return 1;
}
*/