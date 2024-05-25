#ifndef symboltable_h
#define symboltable_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Trie_node{
    char letter;
    struct Trie_nodes_list* children;
    struct Trie_node* next;
    int is_end;
    int value;
    int line;
    char* scope;
}Trie_node;



typedef struct Trie_nodes_list{
    struct Trie_node *start;
} Trie_nodes_list;



typedef struct SymbolTable {
    struct Trie_node *head;
    struct SymbolTable* next;
    struct SymbolTable* prev;
    int size;
} SymbolTable;

typedef struct SymbolTableList {
    struct SymbolTable *start;
} SymbolTableList;


Trie_node* create_trie_node(char letter);

Trie_nodes_list* create_trie_nodes_list();

Trie_node* find_letter_on_list(Trie_nodes_list* list, char letter);

Trie_node* add_letter_to_list(Trie_nodes_list* list, char letter);

void insert_word(SymbolTable* table, char* word);

void insert_word_with_value(SymbolTable* table, char* word, int value);

int update_value_node(Trie_node* root, char* word, int value);

Trie_node* find_word(Trie_node* root, char* word);

void print_trie(Trie_node* root, int level);

SymbolTable* create_symbol_table();

SymbolTableList* create_symboltable_list();

void insert_symboltable_on_list(SymbolTableList* list, SymbolTable* table);

SymbolTable* pop_symboltable_stack(SymbolTableList* symboltable_stack);

void print_symbol_table(SymbolTable *table);

void print_trie_node(Trie_node *node, char *buffer, int depth);
#endif