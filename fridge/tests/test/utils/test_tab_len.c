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

Test(tab_len, simple_display_0)
{
    //int tab_len(char **tab)
    cr_redirect_stderr();
    tab_len((char **)0x0);
    cr_assert_stderr_eq_str("\033[32;01mtab_len:\033[00m \
        The 2d_array is \033[34;01mNULL\033[00m\n");
}

Test(tab_len, simple_display_1)
{
    //int tab_len(char **tab)
    char *test[] = {"simple_", "display_", "1", (char *)0x0};
    int output = tab_len(test);
    int expected = 3;
    cr_assert_eq(output, expected);
}
