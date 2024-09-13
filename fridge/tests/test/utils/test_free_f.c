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

Test(free_f, str_equal_NULL)
{
    //void *free_f(void *ptr)
    cr_redirect_stderr();
    free_f((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mfree_f:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
}

Test(free_2d_array, str_equal_NULL)
{
    //void *free_f(void *ptr)
    cr_redirect_stderr();
    free_2d_array((char **)0x0);
    cr_assert_stderr_eq_str("\033[32;01mfree_2d_array:\033[00m \
        The 2d_array is \033[34;01mNULL\033[00m\n");
}

Test(free_2d_array, simple_free)
{
    //void *free_f(void *ptr)
    cr_redirect_stderr();
    char **tab = malloc(sizeof(char *) * 4);
    tab[0] = my_strdup("str");
    tab[1] = my_strdup("equal");
    tab[2] = my_strdup("NULL");
    tab[3] = (char *)0x0;
    free_2d_array(tab);
}

Test(free_3d_array, str_equal_NULL)
{
    //void *free_f(void *ptr)
    cr_redirect_stderr();
    free_3d_array((char ***)0x0);
    cr_assert_stderr_eq_str("\033[32;01mfree_3d_array:\033[00m \
        The 3d_array is \033[34;01mNULL\033[00m\n");
}

Test(free_3d_array, simple_free)
{
    //void *free_f(void *ptr)
    cr_redirect_stderr();
    char **tab_f = malloc(sizeof(char *) * 4);
    tab_f[0] = my_strdup("str");
    tab_f[1] = my_strdup("equal");
    tab_f[2] = my_strdup("NULL");
    tab_f[3] = (char *)0x0;
    char ***tab = malloc(sizeof(char **) * 2);
    tab[0] = tab_f;
    tab[1] = (char **)0x0;
    free_3d_array(tab);
}
