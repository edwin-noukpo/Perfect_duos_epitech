/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/


#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../../../include/utils.h"

void print_list(doubly_linked_t *doubly)
{
    doubly_linked_t *tmp = (doubly_linked_t *)0x0;

    if (!doubly)
        return;
    tmp = doubly;
    while (tmp) {
        mini_printf("no - %d %s\n", tmp->data->id, tmp->data->var);
        tmp = tmp->next;
    }
    return;
}
