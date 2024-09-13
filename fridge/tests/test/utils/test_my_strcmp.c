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

Test(my_strcmp, s1_equal_NULL)
{
    //int my_strcmp(char *s1, char *s2)
    cr_redirect_stderr();
    my_strcmp((char *)0x0, "(char *)0x0");
    cr_assert_stderr_eq_str("\033[32;01mmy_strcmp:\033[00m \
        The s1 is \033[34;01mNULL\033[00m\n");
}

Test(my_strcmp, s2_equal_NULL)
{
    //int my_strcmp(char *s1, char *s2)
    cr_redirect_stderr();
    my_strcmp("(char *)0x0", (char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strcmp:\033[00m \
        The s2 is \033[34;01mNULL\033[00m\n");
}

Test(my_strcmp, s1_equal_s2)
{
    //int my_strcmp(char *s1, char *s2)
    char *test = "(char *)0x0";
    int output = my_strcmp(test, test);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(my_strcmp, s1_superior_s2)
{
    //int my_strcmp(char *s1, char *s2)
    char *test1 = "(char *)0x0(char *)0x0";
    char *test2 = "(char *)0x0";
    int output = my_strcmp(test1, test2);
    int expected = 40;
    cr_assert_eq(output, expected);
}

Test(my_strcmp, s2_different_s1)
{
    //int my_strcmp(char *s1, char *s2)
    char *test1 = "MARVIN";
    char *test2 = "EPITECH";
    int output = my_strcmp(test1, test2);
    int expected = 8;
    cr_assert_eq(output, expected);
}
