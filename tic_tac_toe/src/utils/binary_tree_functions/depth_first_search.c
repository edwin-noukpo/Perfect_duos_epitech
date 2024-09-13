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

int depth_first_search(tree_t *tree, void *data)
{
    if (!tree) {
        err_putstr("\033[32;01mdepth_first_search:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return 1;
    }
    if (!my_strcmp((char *)tree->value, (char *)data)) {
        mini_printf("Element -> depth_first_search: %s\n", tree->value);
        return 0;
    }
    if (tree->left_tree)
        if (!depth_first_search(tree->left_tree, data))
            return 0;
    if (tree->right_tree)
        if (!depth_first_search(tree->right_tree, data))
            return 0;
    return 1;
}

int depth_first_search_2(tree_t *tree, int data)
{
    if (!tree) {
        err_putstr("\033[32;01mdepth_first_search:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return 1;
    }
    if (tree->id == data) {
        return 0;
    }
    if (tree->left_tree)
        if (!depth_first_search_2(tree->left_tree, data))
            return 0;
    if (tree->right_tree)
        if (!depth_first_search_2(tree->right_tree, data))
            return 0;
    return 1;
}
