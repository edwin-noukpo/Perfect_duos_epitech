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

void assenmbly_fractals(fractal_t *frac, char **pattern, int row, int col)
{
    int x = 0;
    int y = 0;
    int b = 0;

    for (int a = row; a < row + frac->height_1; a++) {
        y = 0;
        for (b = col; b < col + frac->width_1; b++) {
            frac->matrix_fractal[a][b] = pattern[x][y];
            y++;
        }
        frac->matrix_fractal[a][b] = 0;
        x++;
    }
}

void dup_older_fractal(fractal_t *frac)
{
    if ((frac->height_fractals * frac->width_fractals) < 0) {
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        free_2d_array(frac->matrix_fractal);
        free_f(frac);
        special_wrtie(2, "Fractal: WARNING ERROR ALLOCATIONS (full memory).\n", 0);
        exit(84);
    }
    frac->tab_dup = my_tabdup(frac->matrix_fractal);
    free_2d_array(frac->matrix_fractal);
    return;
}

void positions_of_each_fractals(fractal_t *frac)
{
    frac->index_x = 0;
    frac->index_y = 0;
    frac->x_coor = malloc(sizeof(int) * frac->height_fractals / frac->height_1);
    if (!frac->x_coor) {
        special_wrtie(2, "Fractal: WARNING ERROR ALLOCATIONS x_coor (full memory).\n", 0);
        exit(84);
    }
    frac->y_coor = malloc(sizeof(int) * frac->width_fractals / frac->width_1);
    if (!frac->y_coor) {
        free_f(frac->x_coor);
        special_wrtie(2, "Fractal: WARNING ERROR ALLOCATIONS y_coor (full memory).\n", 0);
        exit(84);
    }
    for (int x = 0; x < frac->height_fractals; x += frac->height_1) {
        frac->x_coor[frac->index_x] = x;
        frac->index_x++;
    }
    for (int y = 0; y < frac->width_fractals; y += frac->width_1) {
        frac->y_coor[frac->index_y] = y;
        frac->index_y++;
    }
}

void create_fractals_s(fractal_t *frac, int x, int y)
{
    if (frac->tab_dup[x][y] == '#')
        assenmbly_fractals(frac, frac->pattern_1,
        frac->x_coor[x], frac->y_coor[y]);
    else
        assenmbly_fractals(frac, frac->pattern_2,
        frac->x_coor[x], frac->y_coor[y]);
    return;
}

void create_fractals(fractal_t *frac)
{
    dup_older_fractal(frac);
    if (!big_malloc_factal(frac)) {
        free_2d_array(frac->pattern_1);
        free_2d_array(frac->pattern_2);
        free_f(frac->matrix_fractal);
        free_f(frac);
        exit(84);
    }
    positions_of_each_fractals(frac);
    frac->index = 0;
    for (int x = 0; x < frac->height_fractals / frac->height_1; x++)
        for (int y = 0; y < frac->width_fractals / frac->width_1; y++)
            create_fractals_s(frac, x, y);
    free_2d_array(frac->tab_dup);
    free_f(frac->x_coor);
    free_f(frac->y_coor);
    return;
}
