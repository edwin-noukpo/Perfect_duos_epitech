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

void disp_matrix(sandpile_t *sand)
{
    for (int x = 0; x < sand->height; x++) {
        for (int y = 0; y < sand->weight; y++)
            mini_printf("%d", sand->sand_matrix[x][y]);
        mini_printf("\n");
    }
    return;
}
