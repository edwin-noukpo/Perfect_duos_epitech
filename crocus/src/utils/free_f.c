/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** Function  to free memory
*/

#include "../../include/utils.h"

void *free_f(void *ptr)
{
    if (!ptr) {
        err_putstr("\033[32;01mfree_f:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    free(ptr);
    return 0;
}
