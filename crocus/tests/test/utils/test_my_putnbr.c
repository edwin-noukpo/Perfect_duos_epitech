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

Test(my_putnbr, simple_display_0)
{
    //int my_putnbr(int nb)
    cr_redirect_stdout();
    int test = 8;
    my_putnbr(test);
    char *expected = "8";
    cr_assert_stdout_eq_str(expected);
}

Test(my_putnbr, simple_display_1)
{
    //int my_putnbr(int nb)
    cr_redirect_stdout();
    int test = -100;
    my_putnbr(test);
    char *expected = "-100";
    cr_assert_stdout_eq_str(expected);
}

Test(my_putnbr, simple_display_2)
{
    //int my_putnbr(int nb)
    cr_redirect_stdout();
    int test = 100;
    my_putnbr(test);
    char *expected = "100";
    cr_assert_stdout_eq_str(expected);
}
