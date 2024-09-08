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

int count_tree_nodes(tree_t *tree)
{
    if (!tree) {
        err_putstr("\033[32;01mCount_tree_nodes:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return 0;
    }
    mini_printf("Tree -> %d\n", tree->id);
    return (count_tree_nodes(tree->right_tree) +
    count_tree_nodes(tree->left_tree) + 1);
}
