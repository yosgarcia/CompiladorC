#ifndef ast_h
#define ast_h
#include <stdio.h>
#include <stdlib.h>

// Enumeración de los tipos de nodos del AST
enum ASTNodeType {
    PROGRAM_NODE,
    FUNCTIONS_NODE,
    FUNCTION_LIST_NODE,
    FUNCTION_NODE,
    FUNCTION_HEAD_NODE,
    FUNCTION_TAIL_NODE,
    RETURN_TYPE_NODE,
    PARAMETERS_NODE,
    PARAMETER_NODE,
    STATEMENT_LIST_NODE,
    IF_STATEMENT_NODE,
    ELSE_IF_NODE,
    ELSE_IF_STATEMENT_NODE,
    FOR_STATEMENT_NODE,
    FOR_DECLARATION_STATEMENT,
    WHILE_STATEMENT_NODE,
    STATEMENT_NODE,
    TAIL_NODE,
    DECLARATION_NODE,
    TYPE_NODE,
    NAMES_NODE,
    NEW_VARIABLE_NODE,
    VARIABLE_NODE,
    VAR_INIT_NODE,
    POINTER_NODE,
    ARRAY_NODE,
    CONSTANT_NODE,
    INIT_NODE,
    VALUES_NODE,
    EXPRESSION_NODE,
    INCR_ID_NODE_NODE,
    INCR_ID_NODE,
    ID_INCR_NODE,
    SIGN_NODE,
    ASSIGNMENT_NODE,
    VAR_REF_NODE,
    FUNCTION_CALL_NODE,
    CALL_PARAMS_NODE,
    CALL_PARAM_NODE,
    ADD_NODE,
    MINUS_NODE,
    ID_NODE,
    STATEMENTS_NODE,
    RETURN_NODE,
    CONTINUE_NODE,
    BREAK_NODE,
    ELSE_NODE,
    STRING_NODE,
    DECR_ID_NODE_NODE,
    DECR_ID_NODE,
    ID_DECR_NODE

};

// Estructura de un nodo del AST
struct NodeAST
{
    struct NodeAST *parent;
    enum ASTNodeType type;
    char *lexema;
    struct children_node_ast *children;
    struct NodeAST *next;
};

// Estructura de la lista de hijos de un nodo del AST
struct children_node_ast
{
    struct NodeAST *start;
};

/*
 * Función: Crear la lista de hijos de un nodo para el AST
 * @return new_list: Lista de hijos creada
*/
struct children_node_ast *create_children_list();

/*
 * Función: Crear un nodo del AST 
 * @param type: Tipo de nodo
 * @param lexema: Lexema del nodo
 * @return new_node: Nodo creado
*/
struct NodeAST *create_ast_node(enum ASTNodeType type, char *lexema);

/*
 * Función: Agregar un hijo a un nodo del AST
 * @param parent: Nodo padre
 * @param child: Nodo hijo
*/
void add_child(struct NodeAST *parent, struct NodeAST *child);

/*
 * Función: Crear un nodo y agregarlo como hijo de otro nodo
 * @param type: Tipo de nodo
 * @param lexema: Lexema del nodo a crear
 * @param parent: Nodo padre
 * @return new_node: Nodo creado
*/
struct NodeAST *create_and_add_node(enum ASTNodeType type, char *lexema, struct NodeAST *parent);

/*
 * Función: Imprimir el arbol AST
 * @param root: Nodo raiz del arbol
 * @param depth: Profundidad actual del nodo
*/
void print_AST_tree(struct NodeAST *root, int depth);



#endif