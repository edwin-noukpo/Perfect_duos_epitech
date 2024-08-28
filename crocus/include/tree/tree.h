/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to count number of line of an array
*/

#ifndef _BINARY_TREE_
    #define _BINARY_TREE_
    #include "../all_linked_list/doubly_linked_list/d_list.h"

typedef struct binary_tree {
    void *value;
    int id;
    struct binary_tree *left_tree;
    struct binary_tree *right_tree;
    struct binary_tree *parent;
} tree_t;

tree_t *assemly_tree_2(tree_t *tree, int data);
void clean_tree(tree_t *tree);
int count_tree_nodes(tree_t *tree);
int depth_first_search(tree_t *tree, void *data);
int depth_first_search_2(tree_t *tree, int data);
void free_dooubly_linked_list(void *data);
tree_t *join_tree(tree_t *left_tree, tree_t *right_tree, void *data);
tree_t *join_tree_2(tree_t *left_tree, tree_t *right_tree, int data);
tree_t *new_tree(void *data);
tree_t *new_tree_2(int data);
void print_tree_prefix(tree_t *tree);
void print_tree_prefix_2(tree_t *tree);
void print_tree_postfix(tree_t *tree);
void print_tree_postfix_2(tree_t *tree);

#endif /* !_TREE_ */
