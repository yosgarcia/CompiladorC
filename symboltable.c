#include "symboltable.h"
#include <stdbool.h>


Trie_node* create_trie_node(char letter){
    Trie_node* new_node = calloc(1, sizeof(Trie_node));
    new_node->letter = letter;
    new_node->is_end = 0;
    new_node->next = NULL;
    new_node->children = NULL;
    return new_node;
}

Trie_nodes_list* create_trie_nodes_list(){
    Trie_nodes_list* new_list = calloc(1, sizeof(Trie_nodes_list));
    new_list->start = NULL;
    return new_list;
}

Trie_node* find_letter_on_list(Trie_nodes_list* list, char letter){
    Trie_node* current = list->start;
    while(current != NULL){
        if(current->letter == letter){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Trie_node* add_letter_to_list(Trie_nodes_list* list, char letter){
    Trie_node* new_node = create_trie_node(letter);
    if (list->start == NULL)
    {
        list->start = new_node;
        return new_node;
    }
    else
    {
        Trie_node *current = list->start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        return new_node;
    }
}
void insert_word(SymbolTable* table, char* word){
    Trie_node* current = table->head;
    for(int i = 0; word[i] != '\0'; i++){
        if(current->children == NULL){
            current->children = create_trie_nodes_list();
        }

        Trie_node* letter = find_letter_on_list(current->children, word[i]);
        if(letter == NULL){
            letter = add_letter_to_list(current->children, word[i]);
        }
        current = letter;
    }
    current->is_end = 1;
    table->size++;
}
void insert_word_with_value(SymbolTable* table, char* word, int value){
    Trie_node* current = table->head;
    for(int i = 0; word[i] != '\0'; i++){
        if(current->children == NULL){
            current->children = create_trie_nodes_list();
        }

        Trie_node* letter = find_letter_on_list(current->children, word[i]);
        if(letter == NULL){
            letter = add_letter_to_list(current->children, word[i]);
        }
        current = letter;
    }
    current->is_end = 1;
    current->value = value;
    table->size++;
}


Trie_node* find_word(Trie_node* root, char* word){
    Trie_node* current = root;
    for(int i = 0; word[i] != '\0'; i++){
        if(current->children == NULL){
            return NULL;
        }

        Trie_node* letter = find_letter_on_list(current->children, word[i]);
        if(letter == NULL){
            return NULL;
        }
        current = letter;
    }
    if(current->is_end){
        return current;
    }
    return NULL;

}
int update_value_node(Trie_node* root, char* word, int value){
    Trie_node* node = find_word(root,word);
    if (node){
        node->value = value;
        return true;
    }
    return false;
}
void print_trie(Trie_node* root, int level){
    if(root == NULL){
        return;
    }

    for (int i = 0; i < level; i++)
    {
        printf(" ");
    }
    if(level > 0){
        printf("|-");
    }

    printf("%c\n", root->letter);
    if(root->children != NULL){
        Trie_node* current = root->children->start;
        while(current != NULL){
            print_trie(current, level + 1);
            current = current->next;
        }
    }
}

SymbolTable* create_symbol_table(){
    SymbolTable* new_table = calloc(1, sizeof(SymbolTable));
    new_table->head = create_trie_node(' ');
    new_table->size = 0;
    return new_table;
}


SymbolTableList* create_symboltable_list(){
    SymbolTableList* new_list = calloc(1, sizeof(SymbolTableList));
    new_list->start = NULL;
    return new_list;
}

void insert_symboltable_on_list(SymbolTableList* list, SymbolTable* table){
    
    if (list->start == NULL)
    {
        list->start = table;
    }
    else
    {
        SymbolTable *current = list->start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = table;
        current->next->prev = current;
    }
}

SymbolTable* pop_symboltable_stack(SymbolTableList* symboltable_stack){
    SymbolTable* current = symboltable_stack->start;
    if(current == NULL){
        return NULL;
    }
    while(current->next != NULL){
        current = current->next;
    }
    if(current->prev != NULL){
        current->prev->next = NULL;
        current->prev = NULL;
    }
    return current;

}


void print_symbol_table(SymbolTable *table) {
    if (table == NULL) {
        printf("Tabla de símbolos vacía.\n");
        return;
    }
    
    printf("Tabla de Símbolos (tamaño: %d):\n", table->size);
    printf("==================================================\n");

    char buffer[256]; // Buffer para construir las palabras
    print_trie_node(table->head, buffer, 0);

    printf("==================================================\n");
}

// Función recursiva para imprimir los nodos del trie como palabras completas
void print_trie_node(Trie_node *node, char *buffer, int depth) {
    if (node == NULL) return;

    // Agrega la letra actual al buffer
    buffer[depth] = node->letter;
    
    // Si es el final de una palabra, imprime la palabra completa
    if (node->is_end) {
        buffer[depth + 1] = '\0'; // Termina la cadena
        printf("Palabra: %s (línea: %d, scope: %s, valor: %d)\n", buffer, node->line, node->scope, node->value);
    }
    
    // Recorrer los hijos del nodo
    if(node->children == NULL) return;
    Trie_node* child = node->children->start;
    while (child != NULL) {
        print_trie_node(child, buffer, depth + 1);
        child = child->next;
    }
}
