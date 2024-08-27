/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** desc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../../include/utils.h"
#include "../../../include/struct.h"
#include "../../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../../include/tree/tree.h"
#include "../../../include/robot.h"


Test(big_malloc_factal, call_function)
{
    // int big_malloc_factal(fractal_t *frac);

    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 0;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};

    frac->height_fractals = INT_MAX;
    frac->width_fractals = 1;

    cr_redirect_stdout();
    // char *expected = "Fractal: WARNING ERROR OVERFLOW HEIGHTS.\n";
    int result = big_malloc_factal(frac);

    // cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, true);

    frac->height_fractals = INT_MAX + 1;
    frac->width_fractals = 1;

    cr_redirect_stdout();
    // char *expected = "Fractal: WARNING ERROR OVERFLOW HEIGHTS.\n";
    result = big_malloc_factal(frac);

    // cr_assert_stdout_eq_str(expected);
    cr_assert_eq(result, true);

    free_2d_array(av);
}
