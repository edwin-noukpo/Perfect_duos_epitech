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

void breadth_first_search_s(tree_t *tree, doubly_linked_t **list)
{
    data_t *da = (data_t *)0x0;

    if (tree->left_tree) {
        da = malloc(sizeof(data_t));
        *da = (data_t) {0, tree->left_tree->value, tree->left_tree};
        insert_at_end(&(*list), da);
    }
    if (tree->right_tree) {
        da = malloc(sizeof(data_t));
        *da = (data_t) {0, tree->right_tree->value, tree->right_tree};
        insert_at_end(&(*list), da);
    }
    return;
}

int breadth_first_search(tree_t *tree, void *data, doubly_linked_t *list)
{
    doubly_linked_t *tmp = list;

    if (!tree) {
        err_putstr("\033[32;01mbreadth_first_search:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return 1;
    }
    if (!my_strcmp((char *)tree->value, (char *)data)) {
        free_dooubly_linked_list(tmp);
        return 0;
    }
    free_f(tmp->data);
    delete_at_the_beginning(&tmp);
    breadth_first_search_s(tree, &tmp);
    if (!tmp)
        return 1;
    mini_printf("Element -> breadth_first_search: %s\n", tmp->data->var);
    if (!breadth_first_search(tmp->data->tree, data, tmp))
        return 0;
    return 1;
}

void breadth_first_search_s_2(tree_t *tree, doubly_linked_t **list)
{
    data_t *da = (data_t *)0x0;

    if (tree->left_tree) {
        da = malloc(sizeof(data_t));
        *da = (data_t) {tree->left_tree->id, 0, tree->left_tree};
        insert_at_end(&(*list), da);
    }
    if (tree->right_tree) {
        da = malloc(sizeof(data_t));
        *da = (data_t) {tree->right_tree->id, 0, tree->right_tree};
        insert_at_end(&(*list), da);
    }
    return;
}

int breadth_first_search_2(tree_t *tree, int data, doubly_linked_t *list)
{
    doubly_linked_t *tmp = list;

    if (!tree) {
        err_putstr("\033[32;01mbreadth_first_search:\033[00m \
        The tree is \033[34;01mundefine\033[00m\n");
        return 1;
    }
    if (tree->id == data) {
        free_dooubly_linked_list(tmp);
        return 0;
    }
    free_f(tmp->data);
    delete_at_the_beginning(&tmp);
    breadth_first_search_s_2(tree, &tmp);
    if (!tmp)
        return 1;
    if (!breadth_first_search_2(tmp->data->tree, data, tmp))
        return 0;
    return 1;
}
