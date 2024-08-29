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

char **my_tabdup(char **tab)
{
    int a = tab_len(tab);
    int x = 0;
    char **tabdup = (char **)0x0;

    tabdup = malloc(sizeof(char *) * (a + 1));
    for (x = 0; tab[x]; x++)
        tabdup[x] = my_strdup(tab[x]);
    tabdup[x] = (char *)0x0;
    return tabdup;
}
