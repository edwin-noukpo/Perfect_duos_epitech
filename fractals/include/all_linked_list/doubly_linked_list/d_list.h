/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/

#ifndef _LINKED_LIST_
    #define _LINKED_LIST_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../../tree/tree.h"

typedef struct data {
    int id;
    char *var;
    tree_t *tree;
} data_t;

typedef struct linked {
    data_t *data;
    struct linked *prev;
    struct linked *next;
} doubly_linked_t;

int breadth_first_search(tree_t *tree, void *data, doubly_linked_t *list);
int breadth_first_search_2(tree_t *tree, int data, doubly_linked_t *list);
doubly_linked_t *creat_new_node(data_t *data);
void delete_at_the_beginning(doubly_linked_t **doubly);
void delete_at_the_end(doubly_linked_t **doubly);
void delete_element(doubly_linked_t **doubly, data_t *data);
void insert_at_beginning(doubly_linked_t **doubly, data_t *data);
void insert_at_end(doubly_linked_t **doubly, data_t *data);
void print_list(doubly_linked_t *doubly);
void print_reverse_list(doubly_linked_t *doubly);

#endif /* !LINKED_LIST */
