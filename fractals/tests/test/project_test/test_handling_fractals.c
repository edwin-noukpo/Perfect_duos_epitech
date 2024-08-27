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

Test(create_fractals, call_function)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    error_handling(frac);
    iteration_zero(frac);
    iterations(frac);
}

Test(create_fractals, call_function_iteration_0)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("0");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    error_handling(frac);
    iteration_zero(frac);
}
