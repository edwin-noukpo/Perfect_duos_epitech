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

Test(disp_tab, 2d_array_equal_NULL)
{
    //void disp_tab(char **tab)
    cr_redirect_stderr();
    disp_tab((char **)0x0);
    cr_assert_stderr_eq_str("\033[32;01mdisp_table:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(disp_tab, simple_2d_array)
{
    //void disp_tab(char **tab)
    cr_redirect_stdout();
    char *tab_test[] = {"simple","2d", "array", (char *)0x0};
    disp_tab(tab_test);
    char *expected = "simple\n2d\narray\n";
    cr_assert_stdout_eq_str(expected);
}
