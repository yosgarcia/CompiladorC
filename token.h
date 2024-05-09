#ifndef token_h
#define token_h
#include <stdio.h>
#include <stdlib.h>


// Enumeracion de los tipos de tokens
enum token_type {
    EOF_SYMBOL = 0,
    KEYWORD,
    IDENTIFIER,
    CONST_INTEGER,
    CONST_FLOAT,
    CONST_STRING,
    OPERATOR_LOGICAL_NOT,
    OPERATOR_ADDRESS,
    OPERATOR_ADDITION,
    OPERATOR_SUBTRACTION,
    OPERATOR_MULTIPLICATION,
    OPERATOR_DIVISION,
    OPERATOR_MODULO,
    OPERATOR_GREATER_THAN,
    OPERATOR_LESS_THAN,
    OPERATOR_BITWISE_OR,
    OPERATOR_BITWISE_XOR,
    OPERATOR_ASSIGN,
    OPERATOR_COMMA,
    OPERATOR_SEMICOLON, 
    OPERATOR_DOT,
    OPERATOR_HASH,
    OPEN_SMALL_BRACKETS,
    CLOSE_SMALL_BRACKETS,
    OPEN_SQUARE_BRACKETS,
    CLOSE_SQUARE_BRACKETS,
    OPEN_CURLY_BRACKETS,
    CLOSE_CURLY_BRACKETS,
    INCOMPLETE_MULTI_COMMENT,
    ERROR
};


// struct para cada uno de los tokens
typedef struct token {
    enum token_type type; // tipo de token
    char *lexeme; // lexema
    int line; //numero de linea
} Token;

/*
 * Funcion: Crear un token
 * @param type: tipo de token
 * @param lexeme: lexema al que pertenece el token
 * @param line: numero de linea en la que aparece el token
 * @return: token creado
 */
Token* createToken(enum token_type type, char *lexeme, int line);

/*
 * Funcion: Imprimir un en forma de string el enum del tipo de token
 * @param token: enum a a convertir
 * @return: string del enum
 */
char* token_type_to_string(enum token_type type);
#endif