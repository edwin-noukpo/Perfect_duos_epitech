/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to compare n caracters in two strings
*/

#include "../../include/utils.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    if (!s1) {
        err_putstr("\033[32;01mmy_strcmp:\033[00m \
        The s1 is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    if (!s2) {
        err_putstr("\033[32;01mmy_strcmp:\033[00m \
        The s2 is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    if (n < 0)
        err_putstr("\033[32;01mmy_strncmp:\033[00m \
        The number is \033[34;01mnegative\033[00m\n");
    for (i = 0; s1[i] && s2[i] && i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return i == n ? 0 : s1[i] - s2[i];
}
