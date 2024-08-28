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

Test(my_strcat, src_equal_NULL)
{
    //char *my_strcat(char *src, char const *dest)
    cr_redirect_stderr();
    my_strcat((char *)0x0, "(char *)0x0");
    cr_assert_stderr_eq_str("\033[32;01mmy_strcat:\033[00m \
        The src is \033[34;01mNULL\033[00m\n");
}

Test(my_strcat, dest_equal_NULL)
{
    //char *my_strcat(char *src, char const *dest)
    cr_redirect_stderr();
    my_strcat("(char *)0x0", (char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strcat:\033[00m \
        The dest is \033[34;01mNULL\033[00m\n");
}

Test(my_strcat, simple_strcat)
{
    //char *my_strcat(char *src, char const *dest)
    char *test = "(char *)0x0";
    char *output = my_strcat(test, test);
    char *expected = "(char *)0x0(char *)0x0";
    cr_assert_str_eq(output, expected);
}
