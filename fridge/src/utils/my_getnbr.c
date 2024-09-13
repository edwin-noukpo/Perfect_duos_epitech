/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** prendre le nombre uniquement
*/

#include "../../include/utils.h"

int my_getnbr(char const *str)
{
    int s = 1;
    int n = 0;
    int i = 0;

    if (!str) {
        err_putstr("\033[32;01mmy_getnbr:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    for (; is_sign(str[i]); i++)
        s *= str[i] == '-' ? -1 : 1;
    for (; str[i]; i++)
        n = (n * 10) + (str[i] - 48);
    return n * s;
}
