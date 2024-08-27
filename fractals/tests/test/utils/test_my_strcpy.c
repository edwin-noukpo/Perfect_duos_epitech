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

Test(my_strcpy, dest_equal_NULL)
{
    //char *my_strcpy(char *dest, char const *src)
    cr_redirect_stderr();
    my_strcpy((char *)0x0, "(char *)0x0");
    cr_assert_stderr_eq_str("\033[32;01mmy_strcpy:\033[00m \
        The dest is \033[34;01mNULL\033[00m\n");
}

Test(my_strcpy, src_equal_NULL)
{
    //char *my_strcpy(char *dest, char const *src)
    cr_redirect_stderr();
    my_strcpy("(char *)0x0", (char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strcpy:\033[00m \
        The src is \033[34;01mNULL\033[00m\n");
}

Test(my_strncpy, dest_equal_NULL)
{
    //char *my_strncpy(char *dest, char const *src, int n)
    cr_redirect_stderr();
    my_strncpy((char *)0x0, "(char *)0x0", 0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strncpy:\033[00m \
        The dest is \033[34;01mNULL\033[00m\n");
}

Test(my_strncpy, src_equal_NULL)
{
    //char *my_strncpy(char *dest, char const *src, int n)
    cr_redirect_stderr();
    my_strncpy("(char *)0x0", (char *)0x0, 0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strncpy:\033[00m \
        The src is \033[34;01mNULL\033[00m\n");
}
