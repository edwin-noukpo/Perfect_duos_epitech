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

Test(is_empty_line, str_equal_NULL)
{
    //int is_empty_line(char *str)
    cr_redirect_stderr();
    is_empty_line((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mis_empty_line:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(is_empty_line, not_empty_line)
{
    //int is_empty_line(char *str)
    char *test = "                      A";
    int output = is_empty_line(test);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_empty_line, not_empty_line_2)
{
    //int is_empty_line(char *str)
    char *test = " \t \t \t \ts \t ";
    int output = is_empty_line(test);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_empty_line, not_empty_line_3)
{
    //int is_empty_line(char *str)
    char *test = "                              EPITECH\0";
    int output = is_empty_line(test);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_empty_line, is_empty_line)
{
    //int is_empty_line(char *str)
    char *test = " \t \t \t \t \t \t";
    int output = is_empty_line(test);
    int expected = 1;
    cr_assert_eq(output, expected);
}
