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

Test(fs_open_file, invalid_file_0)
{
    //int fs_open_file(char const *filepath)
    cr_redirect_stderr();
    fs_open_file((char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mfs_open_file:\033[00m \
        The filepath is \033[34;01mNULL\033[00m\n");
}

Test(fs_open_file, invalid_file_1)
{
    //int fs_open_file(char const *filepath)
    cr_redirect_stderr();
    char *test = "error_file";
    fs_open_file(test);
    cr_assert_stderr_eq_str("\033[32;01mfs_open_file:\033[00m \
        error of openning of \"\033[34;01merror_file\033[00m\"\n");
}

Test(fs_open_file, valid_file)
{
    //int fs_open_file(char const *filepath)
    char *test = "include/tree/tree.h";
    fs_open_file(test);
}
