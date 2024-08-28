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

Test(err_mini_printf, simple_err_display)
{
    //int err_mini_printf(const char *format, ...)
    cr_redirect_stderr();
    err_mini_printf("err_mini_printf\n");
    char *expected = "err_mini_printf\n";
    cr_assert_stderr_eq_str(expected);
}

Test(err_mini_printf, simple_err_pp_display)
{
    //int err_mini_printf(const char *format, ...)
    int test = 8;
    cr_redirect_stderr();
    err_mini_printf("%%\n", test);
    char *expected = "%\n";
    cr_assert_stderr_eq_str(expected);
}

Test(err_mini_printf, simple_err_pd_display)
{
    //int err_mini_printf(const char *format, ...)
    int test = 8;
    cr_redirect_stderr();
    err_mini_printf("%d\n", test);
    char *expected = "8\n";
    cr_assert_stderr_eq_str(expected);
}

Test(err_mini_printf, simple_err_ps_display)
{
    //int err_mini_printf(const char *format, ...)
    char *test = "simple_err_ps_display";
    cr_redirect_stderr();
    err_mini_printf("%s\n", test);
    char *expected = "simple_err_ps_display\n";
    cr_assert_stderr_eq_str(expected);
}

Test(err_mini_printf, simple_err_pc_display)
{
    //int err_mini_printf(const char *format, ...)
    char test = '8';
    cr_redirect_stderr();
    err_mini_printf("%c\n", test);
    char *expected = "8\n";
    cr_assert_stderr_eq_str(expected);
}

Test(err_mini_printf, simple_err_display_2)
{
    //int err_mini_printf(const char *format, ...)
    char *test_s = "am";
    char test_c = 'a';
    int test_d = 18;
    cr_redirect_stderr();
    err_mini_printf("I %s %c Man. I have %d years old\n", test_s, test_c, test_d);
    char *expected = "I am a Man. I have 18 years old\n";
    cr_assert_stderr_eq_str(expected);
}
