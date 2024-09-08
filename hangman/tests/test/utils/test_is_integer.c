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

Test(is_integer, str_equal_NULL)
{
    //int is_integer(char const *str)
    cr_redirect_stderr();
    is_integer((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mis_integer:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(is_integer, simple_test)
{
    //int is_integer(char const *str)
    char *test = "++++++++++-----------01234";
    int output = is_integer(test);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_integer, no_integer)
{
    //int is_integer(char const *str)
    char *test = "01234A";
    int output = is_integer(test);
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_integer, no_integer_2)
{
    //int is_integer(char const *str)
    char *test = "";
    int output = is_integer(test);
    int expected = 1;
    cr_assert_eq(output, expected);
}
