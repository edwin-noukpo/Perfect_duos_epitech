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

Test(my_getnbr, str_equal_NULL)
{
    //int my_getnbr(char const *str)
    cr_redirect_stderr();
    my_getnbr((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_getnbr:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}


Test(my_getnbr, simple_test)
{
    //int my_getnbr(char const *str)
    char *test = "+++++----------++++16";
    int output = my_getnbr(test);
    int expected = 16;
    cr_assert_eq(output, expected);
}
