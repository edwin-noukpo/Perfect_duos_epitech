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
#include "../../../include/robot.h"

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

Test(tab_len, simple_err)
{
    three_tab_len((char ***)0x0);
}
Test(tab_len, simple_count)
{
    char *tab_number = "0123456789";
    char *tab_string = "astek";
    char letter;
    char **temp = (char **)0x0;
    int len_number = my_strlen(tab_number);
    char ***tab_crocus = malloc(sizeof(char **) * (len_number + 1));
    int x = 0;
    int nb = 0;

    for (x = 0; tab_number[x]; x++) {
        nb = tab_number[x] - '0';
        temp = get_tab_number(nb);
        if (tab_string) {
            letter = crocus_character(tab_string, nb);
            temp = change_letter(temp, letter);
        }
        tab_crocus[x] = temp;
    }
    tab_crocus[x] = (char **)0x0;
    int output = three_tab_len(tab_crocus);
    int expected = 10;
    cr_assert_eq(output, expected);
}
