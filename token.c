#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"



/*
 * Funcion: Imprimir un en forma de string el enum del tipo de token
 * @param token: enum a a convertir
 * @return: string del enum
 */
char* token_type_to_string(enum token_type type) {
    switch (type) {
        case EOF_SYMBOL: return "EOF_SYMBOL";
        case KEYWORD: return "KEYWORD";
        case IDENTIFIER: return "IDENTIFIER";
        case CONST_INTEGER: return "CONST_INTEGER";
        case CONST_FLOAT: return "CONST_FLOAT";
        case CONST_STRING: return "CONST_STRING";
        case OPERATOR_LOGICAL_NOT: return "OPERATOR_LOGICAL_NOT";
        case OPERATOR_ADDRESS: return "OPERATOR_ADDRESS";
        case OPERATOR_ADDITION: return "OPERATOR_ADDITION";
        case OPERATOR_SUBTRACTION: return "OPERATOR_SUBTRACTION";
        case OPERATOR_MULTIPLICATION: return "OPERATOR_MULTIPLICATION";
        case OPERATOR_DIVISION: return "OPERATOR_DIVISION";
        case OPERATOR_MODULO: return "OPERATOR_MODULO";
        case OPERATOR_GREATER_THAN: return "OPERATOR_GREATER_THAN";
        case OPERATOR_LESS_THAN: return "OPERATOR_LESS_THAN";
        case OPERATOR_BITWISE_OR: return "OPERATOR_BITWISE_OR";
        case OPERATOR_BITWISE_XOR: return "OPERATOR_BITWISE_XOR";
        case OPERATOR_ASSIGN: return "OPERATOR_ASSIGN";
        case OPERATOR_COMMA: return "OPERATOR_COMMA";
        case OPERATOR_SEMICOLON: return "OPERATOR_SEMICOLON";
        case OPERATOR_DOT: return "OPERATOR_DOT";
        case OPERATOR_HASH: return "OPERATOR_HASH";
        case OPEN_SMALL_BRACKETS: return "OPEN_SMALL_BRACKETS";
        case CLOSE_SMALL_BRACKETS: return "CLOSE_SMALL_BRACKETS";
        case OPEN_SQUARE_BRACKETS: return "OPEN_SQUARE_BRACKETS";
        case CLOSE_SQUARE_BRACKETS: return "CLOSE_SQUARE_BRACKETS";
        case OPEN_CURLY_BRACKETS: return "OPEN_CURLY_BRACKETS";
        case CLOSE_CURLY_BRACKETS: return "CLOSE_CURLY_BRACKETS";
        case ERROR: return "ERROR";
        case INCOMPLETE_MULTI_COMMENT: return "INCOMPLETE_MULTI_COMMENT";
        default: return "UNKNOWN_TOKEN_TYPE";
    }
}


/*
 * Funcion: Crear un token
 * @param type: tipo de token
 * @param lexeme: lexema al que pertenece el token
 * @param line: numero de linea en la que aparece el token
 * @return: token creado
 */
Token* createToken(enum token_type type, char *lexeme, int line) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = type;
    token->lexeme = strdup(lexeme); // Copia el lexema para evitar problemas de asignación de memoria
    token->line = line;
    return token;
}

