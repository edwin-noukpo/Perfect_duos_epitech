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

Test(is_char, str_equal_NULL)
{
    //int is_char(char const *str)
    cr_redirect_stderr();
    is_char((char *)0x0, ' ');
    cr_assert_stderr_eq_str("\033[32;01mis_char:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(is_char, simple_test_0)
{
    //int is_char(char const *str)
    char *test = "MARVIN EPITECH";
    int output = is_char(test, ' ');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_char, simple_test_1)
{
    //int is_char(char const *str)
    char *test = "MARVINEPITECH";
    int output = is_char(test, ' ');
    int expected = 0;
    cr_assert_eq(output, expected);
}
