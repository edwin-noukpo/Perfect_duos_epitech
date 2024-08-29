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


void free_sand(sandpile_t *sand)
{
    free_2d_array(sand->char_matrix);
    free_f(sand->content);
    for (int x = 0; x < sand->height; x++)
        free_f(sand->sand_matrix[x]);
    free_f(sand->sand_matrix);
    free_f(sand);
    return;
}
