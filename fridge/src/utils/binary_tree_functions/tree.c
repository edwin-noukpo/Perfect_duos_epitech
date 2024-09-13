/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to compare n caracters in two strings
*/

#include "../../../include/utils.h"
#include "../../../include/struct.h"
#include "../../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../../include/tree/tree.h"

tree_t *new_tree(void *data)
{
    tree_t *creat_tree = malloc(sizeof(tree_t));

    *creat_tree = (tree_t) {data, 0,
    (tree_t *)0x0, (tree_t *)0x0, (tree_t *)0x0};
    return creat_tree;
}

tree_t *new_tree_2(int data)
{
    tree_t *creat_tree = malloc(sizeof(tree_t));

    *creat_tree = (tree_t) {(void *)0x0,
    data, (tree_t *)0x0, (tree_t *)0x0, (tree_t *)0x0};
    return creat_tree;
}
