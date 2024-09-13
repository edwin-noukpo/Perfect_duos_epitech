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
        return 1;
    }
    if (*map == '\0')
        return 1;
    while (map[i + 1])
        if ((map[i] >= 'a' && map[i] <= 'z') ||
        (map[i] >= '0' && map[i] <= '9') || (map[i] == '_'))
            i++;
        else
            return 1;
    return 0;
}
