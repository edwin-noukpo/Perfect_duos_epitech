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

void print_tree_prefix(tree_t *tree)
{
    if (!tree) {
        err_putstr("\033[32;01mprint_tree_prefix:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return;
    }
    if (tree->parent)
        mini_printf("(%s) --> (%s)\n",
        (char *)tree->parent->value, (char *)tree->value);
    else
        mini_printf("(%s)\n", (char *)tree->value);
    if (tree->left_tree)
        print_tree_prefix(tree->left_tree);
    if (tree->right_tree)
        print_tree_prefix(tree->right_tree);
    return;
}

void print_tree_postfix(tree_t *tree)
{
    if (!tree) {
        err_putstr("\033[32;01mprint_tree_postfix:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return;
    }
    if (tree->parent)
        mini_printf("(%s) --> (%s)\n",
        (char *)tree->parent->value, (char *)tree->value);
    else
        mini_printf("(%s)\n", (char *)tree->value);
    if (tree->right_tree)
        print_tree_postfix(tree->right_tree);
    if (tree->left_tree)
        print_tree_postfix(tree->left_tree);
    return;
}
