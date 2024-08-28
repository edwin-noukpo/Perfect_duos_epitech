/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to compare two strings
*/

#include "../../include/utils.h"

int my_strcmp(char *s1, char *s2)
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
    for (i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}
