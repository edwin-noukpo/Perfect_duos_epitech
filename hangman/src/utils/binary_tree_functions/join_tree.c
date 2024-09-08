/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include "../../../include/utils.h"
#include "../../../include/struct.h"
#include "../../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../../include/tree/tree.h"

tree_t *join_tree(tree_t *left_tree, tree_t *right_tree, void *data)
{
    tree_t *creat_new_tree = new_tree(data);

    creat_new_tree->left_tree = left_tree;
    creat_new_tree->right_tree = right_tree;
    if (left_tree)
        left_tree->parent = creat_new_tree;
    if (right_tree)
        right_tree->parent = creat_new_tree;
    return creat_new_tree;
}

void print_tree_prefix_2(tree_t *tree)
{
    if (!tree) {
        err_putstr("\033[32;01mprint_tree_prefix:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return;
    }
    if (tree->parent) {
        if (!tree->left_tree)
            mini_printf("(%d) --> (%d) --> L_NULL\n",
            tree->parent->id, tree->id);
        if (!tree->right_tree)
            mini_printf("(%d) --> (%d) --> R_NULL\n",
            tree->parent->id, tree->id);
    } else
        mini_printf("(%d)\n", tree->id);
    if (tree->left_tree)
        print_tree_prefix_2(tree->left_tree);
    if (tree->right_tree)
        print_tree_prefix_2(tree->right_tree);
    return;
}

void print_tree_postfix_2(tree_t *tree)
{
    if (!tree) {
        err_putstr("\033[32;01mprint_tree_postfix:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return;
    }
    if (tree->parent)
        mini_printf("(%d) --> (%d)\n",
        tree->parent->id, tree->id);
    else
        mini_printf("(%d)\n", tree->id);
    if (tree->right_tree)
        print_tree_postfix_2(tree->right_tree);
    if (tree->left_tree)
        print_tree_postfix_2(tree->left_tree);
    return;
}
