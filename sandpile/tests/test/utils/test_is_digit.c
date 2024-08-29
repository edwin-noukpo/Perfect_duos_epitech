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

Test(is_digit, charactere_0)
{
    //int is_digit(char c)
    int output = is_digit('A');
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_digit, charactere_1)
{
    //int is_digit(char c)
    int output = is_digit('0');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_digit, charactere_3)
{
    //int is_digit(char c)
    int output = is_digit(' ');
    int expected = 0;
    cr_assert_eq(output, expected);
}
