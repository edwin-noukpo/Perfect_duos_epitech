/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/

#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"

void insert_at_beginning(doubly_linked_t **doubly, data_t *data)
{
    doubly_linked_t *new_node = creat_new_node(data);

    if (!(*doubly)) {
        (*doubly) = new_node;
        return;
    }
    (new_node)->next = (*doubly);
    (*doubly)->prev = new_node;
    (*doubly) = new_node;
    return;
}
