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

Test(count_word, str_equal_NULL)
{
    //int count_word(char const *str, int (*func)(char))
    cr_redirect_stderr();
    int output = count_word((char *)0x0, &is_anum);
    cr_assert_eq(output, -1);
    cr_assert_stderr_eq_str("\033[32;01mcount_word:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(count_word, simple_count_str)
{
    //int count_word(char const *str, int (*func)(char))
    char const *test = "simple test on countword 012345";
    int output = count_word(test, &is_anum);
    int expected = 5;
    cr_assert_eq(output, expected);
}

Test(count_word, simple_count_str_2)
{
    //int count_word(char const *str, int (*func)(char))
    char const *test = "            ";
    int output = count_word(test, &is_anum);
    int expected = 0;
    cr_assert_eq(output, expected);
}
