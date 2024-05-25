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
 * 
 * 
 * Flex lexer.l
 * gcc principal.c linkedList.c preprocessor.c token.c lex.yy.c -o programa

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "preprocessor.h"
#include "token.h"
#include "symboltable.h"
//#include "parser.y"
#define MAX_LINE_LENGTH 256
int parse_xd(char* file);

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
void start_scanning(){
    Token* token;
    while((token = get_token()) != NULL){
        //printf("%s %s\n",token_type_to_string(token->type),token->lexeme);
        // Hace algo con el token
    }
    
}


int main(int argc, char *argv[]) {
    /*
    if (argc != 2) {
        printf("argumentos invalidos");
        return 1;
    }
    
    const char *source_file = argv[1];
    start_preprocess(source_file);
    FILE* file = fopen("processedfile.c","r");
    //yyin = file;
    Token* token;
    //start_scanning();
    SymbolTable* s = create_symbol_table();
    insert_word(s,"ELPEPE");
    
    insert_word_with_value(s,"EL",5);
    insert_word_with_value(s,"maxlatysh",52);
    bool b =  update_value_node(s->head,"a",4);
    if (b == false){
        printf("error\n");
    }
    
    print_symbol_table(s);
    printf("fin_impresion\n");
    bool bb =  update_value_node(s->head,"ELPEPE",4);
    print_symbol_table(s);
    */
    int w = parse_xd("processedfile.c");

    return 0;
}
