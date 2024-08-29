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

Test(is_anum, charactere_0)
{
    //is_anum(char const c)
    int output = is_anum('A');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_anum, charactere_1)
{
    //is_anum(char const c)
    int output = is_anum('B');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_anum, charactere_2)
{
    //is_anum(char const c)
    int output = is_anum('a');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_anum, charactere_3)
{
    //is_anum(char const c)
    int output = is_anum('b');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_anum, charactere_4)
{
    //is_anum(char const c)
    int output = is_anum('0');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_anum, charactere_5)
{
    //is_anum(char const c)
    int output = is_anum('9');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_anum, bad_charactere)
{
    //is_anum(char const c)
    int output = is_anum(' ');
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_anum, bad_charactere_2)
{
    //is_anum(char const c)
    int output = is_anum('_');
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_anum, bad_charactere_3)
{
    //is_anum(char const c)
    int output = is_anum('*');
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_alpha, charactere_0)
{
    //is_alpha(char const c
    int output = is_alpha('A');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_alpha, charactere_1)
{
    //is_alpha(char const c
    int output = is_alpha('B');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_alpha, charactere_2)
{
    //is_alpha(char const c
    int output = is_alpha('a');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_alpha, charactere_3)
{
    //is_alpha(char const c
    int output = is_alpha('b');
    int expected = 1;
    cr_assert_eq(output, expected);
}

Test(is_alpha, bad_charactere)
{
    //is_alpha(char const c
    int output = is_alpha(' ');
    int expected = 0;
    cr_assert_eq(output, expected);
}

Test(is_alpha, bad_charactere_2)
{
    //is_alpha(char const c
    int output = is_alpha('_');
    int expected = 0;
    cr_assert_eq(output, expected);
}
