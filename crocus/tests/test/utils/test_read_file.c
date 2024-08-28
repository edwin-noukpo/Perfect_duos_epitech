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

Test(read_map, invalid_file_0)
{
    //int read_map(int fd, char *filepath)
    cr_redirect_stderr();
    read_map(0, (char *)0x0);
    cr_assert_stderr_eq_str("\033[32;01mread_map:\033[00m \
        The filepath is \033[34;01mNULL\033[00m\n");
}

Test(read_map, valid_file)
{
    //int read_map(int fd, char *filepath)
    char *test = "tests/test/utils/test_read";
    int fd = fs_open_file(test);
    char *output = read_map(fd, test);
    char *expected = "good\n";
    cr_assert_str_eq(output, expected);
}
