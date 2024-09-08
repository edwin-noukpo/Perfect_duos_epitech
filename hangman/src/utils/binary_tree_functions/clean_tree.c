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

void clean_tree(tree_t *tree)
{
    if (!tree)
        return;
    clean_tree(tree->left_tree);
    clean_tree(tree->right_tree);
    free_f(tree);
    return;
}
