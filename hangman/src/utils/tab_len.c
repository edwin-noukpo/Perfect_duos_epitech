/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to count number of line of an array
*/

#include "../../include/utils.h"

int tab_len(char **tab)
{
    int i = 0;

    if (!tab) {
        err_putstr("\033[32;01mtab_len:\033[00m \
        The 2d_array is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    for (i = 0; tab[i]; i++);
    return i;
}

int three_tab_len(char ***tab)
{
    int i = 0;

    if (!tab) {
        err_putstr("\033[32;three_tab_len:\033[00m \
        The 3d_array is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    for (i = 0; tab[i]; i++);
    return i;
}
