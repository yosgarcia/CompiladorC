%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"
%}

%option noyywrap
%option yylineno

%{
// Incluye el archivo de encabezado de token
#include "token.h"
%}

%%
"//".*       { /* Ignora los comentarios de una línea */ }
"/*"([^*]|\n|\r\n)*"*/" { /* Ignora los comentarios de varias líneas */ }

"/*"([^"*"]|(["*"]+[^"*/"]))* { return INCOMPLETE_MULTI_COMMENT;}

"#include".* { /* Ignora los #include */}
"#define".* { /* Ignora los #define */}
"auto"|"enum"|"const"|"goto"|"double"|"case"|"float"|"default" { return KEYWORD; }
"struct"|"register"|"unsigned"|"sizeof"|"int"|"typedef"|"short" { return KEYWORD; }
"volatile"|"break"|"extern"|"continue"|"if"|"else"|"char"|"for"|"do" { return KEYWORD; }
"switch"|"return"|"void"|"static"|"long"|"union"|"signed"|"while" { return KEYWORD; }

[a-zA-Z_][a-zA-Z0-9_-]* { return IDENTIFIER; }
(-?[1-9][0-9]{0,4})|0 { return CONST_INTEGER; }
[0-9]+[a-zA-Z_-][a-zA-Z0-9_-]* { return ERROR; }
(-?[0-9]+\.[0-9]+)  { return CONST_FLOAT; }
\"[^\n\"]*\" { return CONST_STRING; }
"!" { return OPERATOR_LOGICAL_NOT; }
"&" { return OPERATOR_ADDRESS; }
"+" { return OPERATOR_ADDITION; }
"-" { return OPERATOR_SUBTRACTION; }
"*" { return OPERATOR_MULTIPLICATION; }
"/" { return OPERATOR_DIVISION; }
"%" { return OPERATOR_MODULO; }
">" { return OPERATOR_GREATER_THAN; }
"<" { return OPERATOR_LESS_THAN; }
"|" { return OPERATOR_BITWISE_OR; }
"^" { return OPERATOR_BITWISE_XOR; }
"=" { return OPERATOR_ASSIGN; }

"," { return OPERATOR_COMMA; }
"." { return OPERATOR_DOT; }
"#" { return OPERATOR_HASH; }
"(" { return OPEN_SMALL_BRACKETS; }
")" { return CLOSE_SMALL_BRACKETS; }
"[" { return OPEN_SQUARE_BRACKETS; }
"]" { return CLOSE_SQUARE_BRACKETS; }
"{" { return OPEN_CURLY_BRACKETS; }
"}" { return CLOSE_CURLY_BRACKETS; }

";" { return OPERATOR_SEMICOLON; }
"\n" { /* Ignore el cambio de linea*/ }
"\t" { /* Ignora el tabulador */ }
" " { /* Ignora el espacio en blanco */ }
. { return ERROR;}

%%

