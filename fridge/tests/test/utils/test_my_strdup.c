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

Test(my_strdup, str_equal_NULL)
{
    //char *my_strdup(char const *str)
    cr_redirect_stderr();
    my_strdup((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strdup:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}


Test(my_strdup, simple_test)
{
    //char *my_strdup(char const *str)
    char *test = "MARVIN";
    char *output = my_strdup(test);
    cr_assert_str_eq(test, output);
    free_f(output);
}
