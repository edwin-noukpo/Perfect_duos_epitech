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

int check_pattern_s(fractal_t *frac)
{
    if (!(frac->height_2 * frac->width_2 == frac->len_2)) {
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        free_f(frac);
        return special_wrtie(2, "Fractal: Bad definition of second pattern.\n", 0);
    }
    if (!(frac->len_1 == frac->len_2)) {
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        free_f(frac);
        return special_wrtie(2, "Fractal: Bad correlation between pattern.\n", 0);
    }
    return 1;
}

int check_pattern(fractal_t *frac)
{
    frac->height_1 = tab_len(frac->pattern_1);
    frac->width_1 = my_strlen(*frac->pattern_1);
    frac->height_2 = tab_len(frac->pattern_2);
    frac->width_2 = my_strlen(*frac->pattern_2);
    frac->len_1 = 0;
    frac->len_2 = 0;
    for (int x = 0; frac->pattern_1[x]; x++)
        frac->len_1 += my_strlen(frac->pattern_1[x]);
    for (int x = 0; frac->pattern_2[x]; x++)
        frac->len_2 += my_strlen(frac->pattern_2[x]);
    if (!(frac->height_1 * frac->width_1 == frac->len_1)) {
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        free_f(frac);
        return special_wrtie(2, "Fractal: Bad definition of first pattern.\n", 0);
    }
    if (!check_pattern_s(frac))
        return 0;
    return 1;
}

int error_handling(fractal_t *frac)
{
    if (!(frac->ac == 4))
        return special_wrtie(2, "Fractal: read guide users.\n", 0);
    if (!is_integer(frac->av[1])) {
        frac->iterations = my_getnbr(frac->av[1]);
        if (frac->iterations < 0)
            return special_wrtie(2, "Fractal: Negative iterations define by users.\n", 0);
    } else
        return special_wrtie(2, "Fractal: Iterations size must be an integer.\n", 0);
    if (!*frac->av[2])
        return special_wrtie(2, "Fractal: First pattern is empty.\n", 0);
    if (!my_cheker(frac->av[2]))
        return special_wrtie(2, "Fractal: First pattern must be composed to '#'/ '@' / '.'.\n", 0);
    if (!*frac->av[3])
        return special_wrtie(2, "Fractal: Second pattern is empty.\n", 0);
    if (!my_cheker(frac->av[3]))
        return special_wrtie(2, "Fractal: Second pattern must be composed to '#'/ '@' / '.'.\n", 0);
    frac->pattern_1 = split(frac->av[2], "@");
    frac->pattern_2 = split(frac->av[3], "@");
    if (!tab_len(frac->pattern_1) || !tab_len(frac->pattern_2)) {
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        return special_wrtie(2, "Fractal: Pattern must be composed to '#'/ '@' / '.'.\n", 0);
    }
    return 1;
}
