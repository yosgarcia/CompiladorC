#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/*
 * Funcion: Crear un nodo
 * @param new_name: nombre del nodo
 * @param new_value: valor del nodo
 * @return: nodo creado
 */
listNode* create_node(char* new_name, char* new_value){
    listNode* new_node = calloc(1, sizeof(listNode));
    new_node->value = new_value;
    new_node->name = new_name;
    return new_node;
}

/*
 * Funcion: Crear una lista
 * @return: lista creada
*/
linkedList* create_list(){
    linkedList* linkedlist = calloc(1,sizeof(linkedList));
    return linkedlist; //lista sin nodos inicio y fin
}

/*
 * Funcion: Buscar un nodo por su nombre
 * @param list: lista en la que se va a buscar
 * @param name: nombre del nodo a buscar
 * @return: nodo encontrado
*/
char* find_name_return_value(linkedList* list, char* value){
    if(list == NULL){
        return NULL;
    }
    if(list->start == NULL){
        return NULL;
    }

    listNode* current = list->finish;
    while(current != NULL){
        if(!strcmp(current->name, value)){
            return current->value;
        }
        current = current->prev;
    }
    return NULL;
}

/*
 * Funcion: Insertar un nodo en la lista
 * @param list: lista en la que se va a insertar
 * @param new_name: nombre del nodo a insertar
 * @param new_value: valor del nodo a insertar
*/
void insert_values(linkedList* list, char* new_name, char* new_value){
    if (list==NULL){
        printf("Null list when inserting values.\n");
        return;
    }
    char* new_value_replacement = find_name_return_value(list,new_value);
    if (new_value_replacement != NULL){
        new_value = new_value_replacement;
    }
    listNode* new_node = create_node(new_name,new_value);
    if (list->start == NULL){
        list->start = new_node;
        list->finish = new_node;

    }
    else{
        listNode* current_node = list->finish;
        current_node->next = new_node;
        new_node->prev = current_node;
        list->finish = new_node;   
    }
}

/*
 * Funcion: Eliminar el primer nodo de la lista
 * @param list: lista en la que se va a eliminar el nodo
*/
void delete_first_node(linkedList* list){
    if(list == NULL){
        return;
    }
    if(list->start == NULL){
        return;
    }
    listNode* temp = list->start;
    temp->next->prev = 
    list->start = temp->next;
    free(temp);
}

/*
 * Funcion: Imprimir la lista
 * @param list: lista a imprimir
*/
void print_list(linkedList* list){
    if(list == NULL){
        printf("Lista es nula\n");
        return;
    }
    if(list->start == NULL){
        printf("La lista está vacía");
        return;
    }

    listNode* current = list->start;
    while(current != NULL){
        printf("Nodo nombre: %s. valor: %s\n",current->name,current->value);
        current = current->next;
    }
}