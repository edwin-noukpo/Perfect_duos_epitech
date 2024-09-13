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

Test(clean_str, str_equal_NULL)
{
    //char *clean_str(char *str)
    cr_redirect_stderr();
    clean_str((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mclean_str:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(clean_str, simple_clean_lowercase_str)
{
    //char *clean_str(char *str)
    char *str = "simple_clean_str";
    char *output = clean_str(str);
    char *expected = "simple_clean_str";
    cr_assert_str_eq(output, expected);
}

Test(clean_str, simple_clean_uppercase_str)
{
    //char *clean_str(char *str)
    char *str = "SIMPLE_CLEAN_STR";
    char *output = clean_str(str);
    char *expected = "SIMPLE_CLEAN_STR";
    cr_assert_str_eq(output, expected);
}

Test(clean_str, simple_clean_number_str)
{
    //char *clean_str(char *str)
    char *str = "0-2-4-6-8-10-12";
    char *output = clean_str(str);
    char *expected = "0-2-4-6-8-10-12";
    cr_assert_str_eq(output, expected);
}

Test(clean_str, simple_clean_str)
{
    //char *clean_str(char *str)
    char *str = "Simple  Clean  Str";
    char *output = clean_str(str);
    char *expected = "Simple Clean Str";
    cr_assert_str_eq(output, expected);
}
