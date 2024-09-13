/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to free a 2D array
*/

#include "../../include/utils.h"

void free_2d_array(char **map)
{
    if (!map) {
        err_putstr("\033[32;01mfree_2d_array:\033[00m \
        The 2d_array is \033[34;01mNULL\033[00m\n");
        return;
    }
    for (int i = 0; map[i]; i++)
        free_f(map[i]);
    free_f(map);
    return;
}
