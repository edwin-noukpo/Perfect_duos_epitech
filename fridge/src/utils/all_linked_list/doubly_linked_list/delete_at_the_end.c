/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/


#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../../../include/utils.h"

void delete_at_the_end(doubly_linked_t **doubly)
{
    doubly_linked_t *tmp = (doubly_linked_t *)0x0;

    if (!(*doubly))
        return;
    tmp = (*doubly);
    if (!tmp->next) {
        (*doubly) = (doubly_linked_t *)0x0;
        free_f(tmp);
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->prev->next = (doubly_linked_t *)0x0;
    free(tmp);
    return;
}
