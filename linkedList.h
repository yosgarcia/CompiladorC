#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la lista
typedef struct listNode {
    struct listNode* next;
    struct listNode* prev;
    char* value;
    char* name;
} listNode;

// Estructura para la lista
typedef struct linkedList {
    struct listNode* start;
    struct listNode* finish;
} linkedList;

/*
 * Funcion: Crear un nodo
 * @param new_name: nombre del nodo
 * @param new_value: valor del nodo
 * @return: nodo creado
 */
listNode* create_node(char* new_name, char* new_value);

/*
 * Funcion: Crear una lista
 * @return: lista creada
*/
linkedList* create_list();

/*
 * Funcion: Buscar un nodo por su nombre
 * @param list: lista en la que se va a buscar
 * @param name: nombre del nodo a buscar
 * @return: nodo encontrado
*/
char* find_name_return_value(linkedList* list, char* value);

/*
 * Funcion: Insertar un nodo en la lista
 * @param list: lista en la que se va a insertar
 * @param new_name: nombre del nodo a insertar
 * @param new_value: valor del nodo a insertar
*/
void insert_values(linkedList* list, char* new_name, char* new_value);

/*
 * Funcion: Eliminar el primer nodo de la lista
 * @param list: lista en la que se va a eliminar el nodo
*/
void delete_first_node(linkedList* list);

/*
 * Funcion: Imprimir la lista
 * @param list: lista a imprimir
*/
void print_list(linkedList* list);

#endif