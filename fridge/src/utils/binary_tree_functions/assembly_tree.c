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

tree_t *assemly_tree_2_s(tree_t *tree, tree_t *tree_c, int data)
{
    if (!tree) {
        tree = tree_c;
        tree_c->parent = tree;
        return tree;
    }
    tree = assemly_tree_2(tree, data);
    clean_tree(tree_c);
    return tree;
}

tree_t *assemly_tree_2(tree_t *tree, int data)
{
    tree_t *creat_new_tree = new_tree_2(data);

    if (!tree) {
        tree = creat_new_tree;
        return tree;
    }
    if (data > tree->id) {
        tree->right_tree = assemly_tree_2_s(tree->right_tree,
        creat_new_tree, data);
        return tree;
    }
    if (data < tree->id) {
        tree->left_tree = assemly_tree_2_s(tree->left_tree,
        creat_new_tree, data);
        return tree;
    }
    if (data == tree->id) {
        clean_tree(creat_new_tree);
        return assemly_tree_2(tree, data + 1);
    }
}
