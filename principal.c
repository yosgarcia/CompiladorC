/*
 * Integrantes: - Yosward Garcia Tellez
 *              - Santiago Ramos Arroyo
 *
 * Instalar pdflatex
 *      sudo apt update
 *      sudo apt install texlive
 * Instalarle un paquete ahi para que funcione pdflatex
 *      sudo apt install texlive-pictures
 * 
 * Ejecutar el código :
 *      flex lexer.l
 *      make run LOCATION=<nombre del archivo a procesar> -f makefile 
 * Ejemplo
 *      make run LOCATION=archivouno.c -f makefile 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "preprocessor.h"
#include "token.h"

#define MAX_LINE_LENGTH 256

extern int yylex(); // Función generada por Flex para obtener el siguiente token
extern FILE *yyin; // Archivo de entrada para Flex
extern int yylineno; // Número de línea actual
extern char* yytext; // Texto del token actual



Token* get_token(){
    enum token_type type = yylex();
    if (type==EOF_SYMBOL){
        return NULL;
    }
    return createToken(type,yytext,yylineno);
}


/*
 * Funcion que inicia el proceso de scanning
 * @param Archivo de salida
 */
void start_scanning(FILE* latex_file){
    Token* token;
    while((token = get_token()) != NULL){
        // Hace algo con el token
    }
    
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("argumentos invalidos");
        return 1;
    }
    
    const char *source_file = argv[1];
    start_preprocess(source_file);
    FILE* file = fopen("processedfile.c","r");
    yyin = file;
    Token* token;
    return 0;
}
