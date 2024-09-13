/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/


#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"

void insert_at_end(doubly_linked_t **doubly, data_t *data)
{
    doubly_linked_t *new_node = creat_new_node(data);
    doubly_linked_t *tmp = (doubly_linked_t *)0x0;

    if (!(*doubly)) {
        (*doubly) = new_node;
        return;
    }
    tmp = (*doubly);
    while ((tmp)->next)
        (tmp) = (tmp)->next;
    (tmp)->next = new_node;
    (new_node)->prev = (tmp);
    return;
}
