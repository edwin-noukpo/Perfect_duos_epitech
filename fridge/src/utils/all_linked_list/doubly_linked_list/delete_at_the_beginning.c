/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/


#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"

void delete_at_the_beginning(doubly_linked_t **doubly)
{
    doubly_linked_t *tmp = (doubly_linked_t *)0x0;

    if (!(*doubly))
        return;
    tmp = (*doubly);
    (*doubly) = (*doubly)->next;
    if ((*doubly))
        (*doubly)->prev = (doubly_linked_t *)0x0;
    free(tmp);
    return;
}
