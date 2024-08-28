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

Test(split, str_equal_NULL)
{
    //char **split(char *str, char *seg)
    cr_redirect_stderr();
    split((char *)0x0, "\n");
    cr_assert_stderr_eq_str("\033[32;01msplit:\033[00m \
        The str is \033[34;01mNULL\033[00m\n");
}

Test(split, seg_equal_NULL)
{
    //char **split(char *str, char *seg)
    cr_redirect_stderr();
    split("EPITECH MARVIN", (char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01msplit:\033[00m \
        The seg is \033[34;01mNULL\033[00m\n");
}

Test(split, simple_test)
{
    //char **split(char *str, char *seg)
    char **test = malloc(sizeof(char *) * 10);
    *test = (char *)0x0;
    char *str = "                            ";
    char *seg = " ";
    char **output = split(str, seg);
    for (int i = 0; test[i]; i++)
        cr_assert_str_eq(output[i], test[i]);
}

Test(split, simple_test_2)
{
    //char **split(char *str, char *seg)
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = my_strdup("2");
    test[2] = my_strdup("3");
    test[3] = my_strdup("4");
    test[4] = my_strdup("5");
    test[5] = NULL;
    char *str = "1\n2\t3 4_5";
    char *seg = "\n\t _";
    char **output = split(str, seg);
    for (int i = 0; test[i]; i++)
        cr_assert_str_eq(output[i], test[i]);
}
