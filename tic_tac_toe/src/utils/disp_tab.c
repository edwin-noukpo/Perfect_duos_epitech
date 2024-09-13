/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** function to display a 2d_array
*/

#include "../../include/utils.h"

void disp_tab(char **tab)
{
    if (!tab) {
        err_putstr("\033[32;01mdisp_table:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return;
    }
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return;
}
