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

int big_malloc_factal(fractal_t *frac)
{
    frac->height_fractals *= frac->height_1;
    if (frac->height_fractals >= INT_MAX)
        return special_wrtie(2, "Fractal: WARNING ERROR OVERFLOW HEIGHTS.\n", 0);
    if (frac->width_fractals >= INT_MAX)
        return special_wrtie(2, "Fractal: WARNING ERROR OVERFLOW WIDTH.\n", 0);
    frac->width_fractals *= frac->width_1;
    frac->matrix_fractal = malloc(sizeof(char *) * (frac->height_fractals + 1));
    if (!frac->matrix_fractal)
        return special_wrtie(2, "Fractal: WARNING ERROR ALLOCATIONS HEIGHTS (full memory).\n", 0);
    for (int x = 0; x < frac->height_fractals; x++) {
        frac->matrix_fractal[x] = malloc(sizeof(char) * (frac->width_fractals + 1));
        if (!frac->matrix_fractal[x])
            return special_wrtie(2, "Fractal: WARNING ERROR ALLOCATIONS WIDTH (full memory).\n", 0);
    }
    frac->matrix_fractal[frac->height_fractals] = (char *)0x0;
    return 1;
}
