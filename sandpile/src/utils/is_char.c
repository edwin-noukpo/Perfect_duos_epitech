/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to search a character in a string
*/

#include "../../include/utils.h"

int is_char(char *str, char c)
{
    if (!str) {
        err_putstr("\033[32;01mis_char:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    for (int i = 0; str[i]; i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}
