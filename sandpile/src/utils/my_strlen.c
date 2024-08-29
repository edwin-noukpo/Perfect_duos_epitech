/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** lenght of a string
*/

#include "../../include/utils.h"

int my_strlen(const char *str)
{
    int i;

    if (!str) {
        err_putstr("\033[32;01mmy_strlen:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    for (i = 0; str[i]; i++);
    return i;
}

int my_strlen_s(const char *str, char stop)
{
    int i;

    if (!str) {
        err_putstr("\033[32;01mmy_strlen:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    for (i = 0; str[i] != stop && str[i]; i++);
    return i;
}
