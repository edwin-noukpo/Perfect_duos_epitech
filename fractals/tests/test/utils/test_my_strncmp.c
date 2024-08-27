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

Test(my_strncmp, s1_equal_NULL)
{
    //int my_strncmp(char *s1, char *s2, int n)
    cr_redirect_stderr();
    my_strncmp((char *)0x0, "(char *)0x0", 0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strcmp:\033[00m \
        The s1 is \033[34;01mNULL\033[00m\n");
}

Test(my_strncmp, s2_equal_NULL)
{
    //int my_strncmp(char *s1, char *s2, int n)
    cr_redirect_stderr();
    my_strncmp("(char *)0x0", (char *)0x0, 0);
    cr_assert_stderr_eq_str("\033[32;01mmy_strcmp:\033[00m \
        The s2 is \033[34;01mNULL\033[00m\n");
}

Test(my_strncmp, negative_n)
{
    //int my_strncmp(char *s1, char *s2, int n)
    char *test = "(char *)0x0";
    cr_redirect_stderr();
    my_strncmp(test, test, -1);
    cr_assert_stderr_eq_str("\033[32;01mmy_strncmp:\033[00m \
        The number is \033[34;01mnegative\033[00m\n");
}

Test(my_strncmp, s1_equal_s2)
{
    //int my_strncmp(char *s1, char *s2, int n)
    char *test = "(char *)0x0";
    int output = my_strncmp(test, test, 5);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(my_strncmp, n_superior_index)
{
    //int my_strncmp(char *s1, char *s2, int n)
    char *test1 = "(char *)000(char *)000";
    char *test2 = "(char *)000";
    int output = my_strncmp(test2, test1, 0);
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(my_strncmp, s1_superior_s2)
{
    //int my_strncmp(char *s1, char *s2, int n)
    char *test1 = "(char *)0x0(char *)0x0";
    char *test2 = "(char *)0x0";
    int output = my_strncmp(test1, test2, 21);
    int expected = 40;
    cr_assert_eq(output, expected);
}

Test(my_strncmp, s2_different_s1)
{
    //int my_strncmp(char *s1, char *s2, int n)
    char *test1 = "MARVIN";
    char *test2 = "EPITECH";
    int output = my_strncmp(test1, test2, 1);
    int expected = 8;
    cr_assert_eq(output, expected);
}
