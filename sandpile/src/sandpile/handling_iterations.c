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

int iterations_handling(sandpile_t *sand)
{
    if (!is_integer(sand->av[3])) {
        sand->iterations = my_getnbr(sand->av[3]);
        if (sand->iterations < 0)
            return special_wrtie(2, "Sandpile: Negative iterations define by users.\n", 0);
    } else
        return special_wrtie(2, "Sandpile: Iterations size must be an integer.\n", 0);
    return 1;
}
