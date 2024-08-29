/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** program that displays characters of a string
*/

#include "../../include/utils.h"

int err_putstr(char const *str)
{
    int i = 0;

    if (!str) {
        err_putstr("\033[32;01merr_putstr:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    while (str[i]) {
        err_putchar(str[i]);
        i++;
    }
    return i;
}
