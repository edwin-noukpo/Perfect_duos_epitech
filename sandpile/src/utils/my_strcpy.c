/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** my_strcpy
*/

#include "../../include/utils.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest) {
        err_putstr("\033[32;01mmy_strcpy:\033[00m \
        The dest is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    if (!src) {
        err_putstr("\033[32;01mmy_strcpy:\033[00m \
        The src is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!dest) {
        err_putstr("\033[32;01mmy_strncpy:\033[00m \
        The dest is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    if (!src) {
        err_putstr("\033[32;01mmy_strncpy:\033[00m \
        The src is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
