/*
** EPITECH PROJECT, 2024
** ROBOT FACTORY
** File description:
** Function to check if a string is an integer
*/

#include "../../include/utils.h"

int is_integer(char const *str)
{
    int i = 0;

    if (!str) {
        err_putstr("\033[32;01mis_integer:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    while (is_sign(str[i]))
        i++;
    while (str[i]) {
        if (!is_digit(str[i]))
            return 1;
        i++;
    }
    if (i == 0)
        return 1;
    return 0;
}
