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

void center_matrix(sandpile_t *sand)
{
    if (!(sand->height % 2))
        sand->x_center = (sand->height / 2) - 1;
    else
        sand->x_center = (sand->height / 2);
    if (!(sand->weight % 2))
        sand->y_center = (sand->weight / 2) - 1;
    else
        sand->y_center = (sand->weight / 2);
    sand->sand_matrix[sand->x_center][sand->y_center] += 1;
}

void sandpile_handling(sandpile_t *sand)
{
    matrix(sand);
    for (int x = 0; x < sand->iterations; x++) {
        center_matrix(sand);
        handling_reaction(sand);
    }
    free_2d_array(sand->char_matrix);
    replace_matrix(sand);
    disp_tab(sand->char_matrix);
    free_sand(sand);
    return;
}
