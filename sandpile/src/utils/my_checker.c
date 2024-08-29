/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include "../../include/utils.h"

int my_cheker(char const *map)
{
    int i = 0;

    if (!map) {
        err_putstr("\033[32;01mmy_cheker:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    if (!*map)
        return 0;
    while (map[i])
        if (map[i] == '#' || map[i] == '@' || map[i] == '.')
            i++;
        else
            return 0;
    return 1;
}
