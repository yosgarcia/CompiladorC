#include "symboltable.h"
#include <stdbool.h>

//Trie

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
// Función recursiva para imprimir los nodos del trie como palabras completas
void print_trie_node(Trie_node *node, char *buffer, int depth) {
    if (node == NULL) return;

    // Agrega la letra actual al buffer
    buffer[depth] = node->letter;
    
    // Si es el final de una palabra, imprime la palabra completa
    if (node->is_end) {
        buffer[depth + 1] = '\0'; // Termina la cadena
        printf("Palabra: %s (línea: %d)\n", buffer, node->line);
    }
    
    // Recorrer los hijos del nodo
    if(node->children == NULL) return;
    Trie_node* child = node->children->start;
    while (child != NULL) {
        print_trie_node(child, buffer, depth + 1);
        child = child->next;
    }
}

int update_value_node(Trie_node* root, char* word, int value){
    Trie_node* node = find_word(root,word);
    if (node){
        node->value = value;
        return true;
    }
    return false;
}

Trie_node* find_word(Trie_node* root, char* word){
    if (root == NULL){
        return NULL;
    }
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

/*
 * SymbolTable  
*/
SymbolTable* create_symbol_table(){
    SymbolTable* new_table = calloc(1, sizeof(SymbolTable));
    new_table->head = create_trie_node(' ');
    new_table->size = 0;
    return new_table;
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

/*
 * SymbolTableList
*/
SymbolTableList* create_symboltable_list(){
    SymbolTableList* new_list = calloc(1, sizeof(SymbolTableList));
    new_list->start = NULL;
    return new_list;
}

SymbolTable* pop_symboltable_stack(SymbolTableList* symboltable_stack){
    SymbolTable* current = symboltable_stack->start;
    if(current == NULL){
        return NULL;
    }
    if(current->next == NULL){
        symboltable_stack->start = NULL;
        return current;
    }
    current->next->prev = NULL;
    symboltable_stack->start = current->next;
    current->next = NULL;
    return current;
}

void insert_symboltable_on_list(SymbolTableList* list, SymbolTable* table){
    if (list->start == NULL)
    {
        list->start = table;
    }
    else
    {
        SymbolTable *current = list->start;
        current->prev = table;
        table->next = current;
        list->start = table;
    }
}

void insert_new_symboltable_on_list(SymbolTableList* list){
    printf("insert_new_symboltable_on_list\n");
    SymbolTable* newTable = create_symbol_table();
    insert_symboltable_on_list(list,newTable);
}

void insert_word_with_value_on_top(SymbolTableList* list, char* word, int value){
    insert_word_with_value(list->start,word,value);
}
void insert_word_on_top(SymbolTableList* list, char* word){
    insert_word(list->start,word);
}

Trie_node* find_word_on_start_symboltablelist(SymbolTableList* list, char* word){
    if (list->start == NULL){
        return NULL;
    }
    return find_word(list->start->head, word);
}
Trie_node* find_word_on_all_symboltablelist(SymbolTableList* list, char* word){
    SymbolTable* symbolTable = list->start;

    if(symbolTable == NULL){
        return NULL;
    }
    while(symbolTable != NULL){
        Trie_node* word_node = find_word(symbolTable->head,word);
        if (word_node != NULL){
            return word_node;
        }
        symbolTable = symbolTable->next;
    }
    return NULL;
}

char* intToStr(int number) {
    int num = number;
    int length = 0;
    int temp = num;
    
    // Cuenta el número de dígitos
    while (temp != 0) {
        length++;
        temp /= 10;
    }
    
    // Maneja el caso de que el número sea 0
    if (number == 0) {
        length = 1;
    }

    // Asigna memoria para la cadena (incluye el terminador nulo)
    char* str = (char*)malloc((length + 1) * sizeof(char));
    str[length] = '\0'; // Terminador nulo

    // Maneja el caso de que el número sea 0
    if (number == 0) {
        str[0] = '0';
        return str;
    }

    // Llena la cadena con los dígitos
    for (int i = length - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }

    return str;
}