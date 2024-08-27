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

Test(my_strlen, str_equal_NULL)
{
    //int my_strlen(const char *str)
    cr_redirect_stderr();
    my_strlen((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strlen:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(my_strlen, simple_strlen_str_0)
{
    //int my_strlen(const char *str)
    char *test = "MARVIN";
    int output = my_strlen(test);
    int expected = 6;
    cr_assert_eq(output, expected);
}

Test(my_strlen_s, str_equal_NULL)
{
    //my_strlen_s(const char *str, char stop)
    cr_redirect_stderr();
    my_strlen_s((char *)0x0, ' ');
    cr_assert_stderr_eq_str("\033[32;01mmy_strlen:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(my_strlen_s, simple_strlen_str_0)
{
    //my_strlen_s(const char *str, char stop)
    char *test = "MARVIN EPITECH";
    int output = my_strlen_s(test, ' ');
    int expected = 6;
    cr_assert_eq(output, expected);
}
