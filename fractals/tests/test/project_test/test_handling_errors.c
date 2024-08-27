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

Test(check_pattern, call_function)
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
    frac->pattern_1 = split("##@#.", "@");
    frac->pattern_2 = split("..@..", "@");
    int result = check_pattern(frac);
    cr_assert_eq(result, true);
}

Test(check_pattern, test_len_1)
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
    frac->pattern_1 = split("##@#", "@");
    frac->pattern_2 = split("..@..", "@");
    cr_redirect_stderr();
    char *expected = "Fractal: Bad definition of first pattern.\n";
    int result = check_pattern(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(check_pattern, test_len_2)
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
    frac->pattern_1 = split("##@#.", "@");
    frac->pattern_2 = split("..@.", "@");
    cr_redirect_stderr();
    char *expected = "Fractal: Bad definition of second pattern.\n";
    int result = check_pattern(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(check_pattern, test_len_1_and_2)
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
    frac->pattern_1 = split("###@#.#@###", "@");
    frac->pattern_2 = split("..@..", "@");
    cr_redirect_stderr();
    char *expected = "Fractal: Bad correlation between pattern.\n";
    int result = check_pattern(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, call_function)
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
    int result = error_handling(frac);
    cr_assert_eq(result, true);
}

Test(error_handling, nb_arguments)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 5;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: read guide users.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, iterations_must_be_integer)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2abc");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: Iterations size must be an integer.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, iterations_must_be_positive)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("-2");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: Negative iterations define by users.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, empty_pattern_1)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: First pattern is empty.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, empty_pattern_2)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("##@#.");
    av[3] = strdup("");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: Second pattern is empty.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, bad_pattern_1)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("##@#.a");
    av[3] = strdup("..@..");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: First pattern must be composed to '#'/ '@' / '.'.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, bad_pattern_2)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("##@#.");
    av[3] = strdup("..@..a");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: Second pattern must be composed to '#'/ '@' / '.'.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}


Test(error_handling, bad_pattern_1_s)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup("@@@@@");
    av[3] = strdup(".@.");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: Pattern must be composed to '#'/ '@' / '.'.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}

Test(error_handling, bad_pattern_2_s)
{
    fractal_t *frac = malloc(sizeof(fractal_t));
    int ac = 4;
    char **av = malloc(sizeof(char *) * 5);

    av[0] = strdup("./fractals");
    av[1] = strdup("2");
    av[2] = strdup(".@.");
    av[3] = strdup("@@@@@");
    av[4] = (char *)0x0;

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    char *expected = "Fractal: Pattern must be composed to '#'/ '@' / '.'.\n";
    cr_redirect_stderr();
    int result = error_handling(frac);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(result, false);
}
