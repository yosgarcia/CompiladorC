#ifndef symboltable_h
#define symboltable_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef union Value{
    int ival;
	double fval;
	char cval;
	char *sval;
}Value;

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


//Trie
Trie_node* create_trie_node(char letter);
Trie_nodes_list* create_trie_nodes_list();
Trie_node* find_letter_on_list(Trie_nodes_list* list, char letter);
Trie_node* add_letter_to_list(Trie_nodes_list* list, char letter);
void print_trie(Trie_node* root, int level);
void print_trie_node(Trie_node *node, char *buffer, int depth);
int update_value_node(Trie_node* root, char* word, int value);
Trie_node* find_word(Trie_node* root, char* word);

//SymbolTable
SymbolTable* create_symbol_table();
void insert_word(SymbolTable* table, char* word);
void insert_word_with_value(SymbolTable* table, char* word, int value);
void print_symbol_table(SymbolTable *table);

//SymbolTableList
SymbolTableList* create_symboltable_list();
SymbolTable* pop_symboltable_stack(SymbolTableList* symboltable_stack);
void insert_symboltable_on_list(SymbolTableList* list, SymbolTable* table);
void insert_new_symboltable_on_list(SymbolTableList* list);
void insert_word_with_value_on_top(SymbolTableList* list, char* word, int value);
void insert_word_on_top(SymbolTableList* list, char* word);
Trie_node* find_word_on_symboltablelist(SymbolTableList* list, char* word);
Trie_node* find_word_on_all_symboltablelist(SymbolTableList* list, char* word);

#endif