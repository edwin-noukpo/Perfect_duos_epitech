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

Test(err_putnbr, simple_display_0)
{
    //int err_putnbr(int nb)
    cr_redirect_stderr();
    int test = 8;
    err_putnbr(test);
    char *expected = "8";
    cr_assert_stderr_eq_str(expected);
}

Test(err_putnbr, simple_display_1)
{
    //int err_putnbr(int nb)
    cr_redirect_stderr();
    int test = -100;
    err_putnbr(test);
    char *expected = "-100";
    cr_assert_stderr_eq_str(expected);
}

Test(err_putnbr, simple_display_2)
{
    //int err_putnbr(int nb)
    cr_redirect_stderr();
    int test = 100;
    err_putnbr(test);
    char *expected = "100";
    cr_assert_stderr_eq_str(expected);
}
