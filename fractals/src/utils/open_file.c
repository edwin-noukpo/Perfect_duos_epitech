/*
** EPITECH PROJECT, 2024
** ok
** File description:
** ok
*/

#include "../../include/utils.h"

int fs_open_file(char const *filepath)
{
    int fd;

    if (!filepath) {
        err_putstr("\033[32;01mfs_open_file:\033[00m \
        The filepath is \033[34;01mNULL\033[00m\n");
        return -1;
    }
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        err_mini_printf("\033[32;01mfs_open_file:\033[00m \
        error of openning of \"\033[34;01m%s\033[00m\"\n", filepath);
        return -1;
    }
    return fd;
}
