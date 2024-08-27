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

int iteration_zero(fractal_t *frac)
{
    if (!check_pattern(frac))
        exit(84);
    frac->matrix_fractal = malloc(sizeof(char *) * 2);
    for (int x = 0; x < 1; x++)
        frac->matrix_fractal[x] = malloc(sizeof(char) * 2);
    **frac->matrix_fractal = '#';
    frac->matrix_fractal[0][1] = '\0';
    frac->matrix_fractal[1] = (char *)0x0;
    if (!frac->iterations) {
        disp_tab(frac->matrix_fractal);
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        free_2d_array(frac->matrix_fractal);
        free_f(frac);
        return 0;
    }
    return 1;
}

int iterations(fractal_t *frac)
{
    for (int x = 0; x < frac->iterations; x++)
        create_fractals(frac);
    disp_tab(frac->matrix_fractal);
    free_2d_array(frac->pattern_1);
    free_2d_array(frac->pattern_2);
    free_2d_array(frac->matrix_fractal);
    free_f(frac);
    return 1;
}
