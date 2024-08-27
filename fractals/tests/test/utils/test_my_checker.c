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

Test(my_cheker, str_equal_NULL)
{
    //int my_cheker(char const *map)
    cr_redirect_stderr();
    my_cheker((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_cheker:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}


Test(my_cheker, simple_test)
{
    //int my_cheker(char const *map)
    char *test = "#####........@@@@@@@@@@@@@@@@";
    int output = my_cheker(test);
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(my_cheker, simple_test_2)
{
    //int my_cheker(char const *map)
    char *test = "#######...........@......s";
    int output = my_cheker(test);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(my_cheker, simple_test_3)
{
    //int my_cheker(char const *map)
    char *test = "";
    int output = my_cheker(test);
    int expected = 0;
    cr_assert_eq(output, expected);
}
