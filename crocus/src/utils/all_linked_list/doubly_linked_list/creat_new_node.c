/*
** EPITECH PROJECT, 2024
** palindrome
** File description:
** palindrome
*/

#include "../../../../include/all_linked_list/doubly_linked_list/d_list.h"

doubly_linked_t *creat_new_node(data_t *data)
{
    doubly_linked_t *new_node = malloc(sizeof(doubly_linked_t));

    *(new_node) = (doubly_linked_t) {data,
    (doubly_linked_t *)0x0, (doubly_linked_t *)0x0};
    return new_node;
}
