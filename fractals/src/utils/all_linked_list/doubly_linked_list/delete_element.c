/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/

#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"

void delete_element_s(doubly_linked_t **doubly,
    doubly_linked_t *tmp, data_t *data)
{
    while (tmp) {
        if (!strcmp(tmp->data->var, data->var))
            break;
        tmp = tmp->next;
    }
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    free(tmp);
    return;
}

void delete_element(doubly_linked_t **doubly, data_t *data)
{
    doubly_linked_t *tmp = (doubly_linked_t *)0x0;

    if (!(*doubly))
        return;
    tmp = (*doubly);
    if (!strcmp(tmp->data->var, data->var)) {
        delete_at_the_beginning(doubly);
        return;
    }
    delete_element_s(doubly, tmp, data);
    return;
}
