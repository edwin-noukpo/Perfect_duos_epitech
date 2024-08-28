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

Test(error_handling, empty_number)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-n");
    av[2] = strdup("");
    av[3] = strdup("-s");
    av[4] = strdup("astek");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Empty number\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}

Test(error_handling, empty_sring)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-n");
    av[2] = strdup("0123456789");
    av[3] = strdup("-s");
    av[4] = strdup("");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Empty string\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}

Test(error_handling, Where_is_the_flag_n)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup(".");
    av[2] = strdup(".");
    av[3] = strdup(".");
    av[4] = strdup(".");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Where is the flag -n ? Read your subject please\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}

Test(error_handling, Where_is_the_flag_s)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-n");
    av[2] = strdup("0123456789");
    av[3] = strdup(".");
    av[4] = strdup(".");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Where is the flag -s ? Read your subject please\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}


Test(error_handling, Why_a_double_definition_of_flag_n)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-n");
    av[2] = strdup("0123456789");
    av[3] = strdup("-n");
    av[4] = strdup("0123456789");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Where is the flag -s ? Read your subject please\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}

Test(error_handling, Argument_must_be_an_integer)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-n");
    av[2] = strdup("0123dfg456789");
    av[3] = strdup("-s");
    av[4] = strdup("astek");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Argument must be an integer\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}

Test(error_handling, Integer_is_not_define)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-s");
    av[2] = strdup("astek");
    av[3] = strdup("12");
    av[4] = strdup("-n");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: Integer is not define\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}

Test(error_handling, String_is_not_define)
{
    crocus_t *croc = (crocus_t *)0x0;
    int ac = 5;
    char **av = malloc(sizeof(char *) * 6);

    av[0] = strdup("./crocus");
    av[1] = strdup("-n");
    av[2] = strdup("0123456789");
    av[3] = strdup("astek");
    av[4] = strdup("-s");
    av[5] = (char *)0x0;
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    char *expected = "Crocus: String is not define\n";
    cr_redirect_stderr();
    int res = error_handling(croc);
    cr_assert_stderr_eq_str(expected);
    cr_assert_eq(res, 1);
}
