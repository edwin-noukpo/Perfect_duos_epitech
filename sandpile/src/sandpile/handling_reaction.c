/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/utils.h"
#include "../../include/struct.h"
#include "../../include/robot.h"
#include "../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../include/tree/tree.h"

int check_grid_s(sandpile_t *sand)
{
    for (sand->y_grain = 0; sand->y_grain < sand->weight; sand->y_grain++)
        if (sand->sand_matrix[sand->x_grain][sand->y_grain] >= 4)
            return 0;
    return 1;
}

int check_grid(sandpile_t *sand)
{
    for (sand->x_grain = 0; sand->x_grain < sand->height; sand->x_grain++)
        if (!check_grid_s(sand))
            return 0;
    return 1;
}

void become_stable(sandpile_t *sand)
{
    sand->sand_matrix[sand->x_grain][sand->y_grain] -= 4;
    if (sand->x_grain + 1 >= 0 && sand->x_grain + 1 < sand->height)
        sand->sand_matrix[sand->x_grain + 1][sand->y_grain] += 1;
    if (sand->x_grain - 1 >= 0 && sand->x_grain - 1 < sand->height)
        sand->sand_matrix[sand->x_grain - 1][sand->y_grain] += 1;
    if (sand->y_grain + 1 >= 0 && sand->y_grain + 1 < sand->weight)
        sand->sand_matrix[sand->x_grain][sand->y_grain + 1] += 1;
    if (sand->y_grain - 1 >= 0 && sand->y_grain - 1 < sand->weight)
        sand->sand_matrix[sand->x_grain][sand->y_grain - 1] += 1;
    return;
}

void handling_reaction(sandpile_t *sand)
{
    while (!check_grid(sand))
        become_stable(sand);
    return;
}
