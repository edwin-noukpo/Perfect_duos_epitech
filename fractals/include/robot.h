/*
** EPITECH PROJECT, 2024
** ASM
** File description:
** ASM
*/

#ifndef _ASM_
    #define _ASM_
    #include <limits.h>

typedef struct fractal_s {
    int ac;
    char **av;
    int iterations;
    char **pattern_1;
    char **pattern_2;
    int height_1;
    int width_1;
    int height_2;
    int width_2;
    int len_1;
    int len_2;
    char **matrix_fractal;
    int height_fractals;
    int width_fractals;
    int index;
    int index_x;
    int index_y;
    int *x_coor;
    int *y_coor;
    char **tab_dup;
} fractal_t;
void assenmbly_fractals(fractal_t *frac, char **pattern, int row, int col);
int big_malloc_factal(fractal_t *frac);
int check_pattern(fractal_t *frac);
int check_pattern_s(fractal_t *frac);
void create_fractals(fractal_t *frac);
void create_fractals_s(fractal_t *frac, int x, int y);
void dup_older_fractal(fractal_t *frac);
int error_handling(fractal_t *frac);
int iteration_zero(fractal_t *frac);
int iterations(fractal_t *frac);
void positions_of_each_fractals(fractal_t *frac);
#endif /* !_ASM_ */
