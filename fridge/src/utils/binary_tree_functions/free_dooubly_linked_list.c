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

void free_dooubly_linked_list(void *data)
{
    doubly_linked_t *tmp = (doubly_linked_t *)data;
    doubly_linked_t *tmp_2 = (doubly_linked_t *)0x0;

    tmp_2 = tmp;
    while (tmp_2) {
        free_f(tmp_2->data);
        tmp_2 = tmp_2->next;
    }
    free_f(tmp);
    return;
}
