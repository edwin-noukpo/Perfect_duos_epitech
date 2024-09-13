/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** Function to check if a line is empty or not
*/

#include "../../include/utils.h"

int is_empty_line(char *str)
{
    if (!str) {
        err_putstr("\033[32;01mis_empty_line:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return 0;
    return 1;
}
