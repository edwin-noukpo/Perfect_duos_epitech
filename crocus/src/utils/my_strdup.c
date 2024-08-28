/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to duplicate a string
*/

#include "../../include/utils.h"

char *my_strdup(char const *str)
{
    char *dest = (char *)0x0;

    if (!str) {
        err_putstr("\033[32;01mmy_strdup:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    dest = my_strcpy(dest, str);
    return dest;
}
