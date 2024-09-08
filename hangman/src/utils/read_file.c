/*
** EPITECH PROJECT, 2024
** ok
** File description:
** ok
*/

#include "../../include/utils.h"

char *read_map(int fd, char *filepath)
{
    struct stat st;
    char *s = NULL;
    int b = 0;

    if (!filepath) {
        err_putstr("\033[32;01mread_map:\033[00m \
        The filepath is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    b = stat(filepath, &st);
    s = malloc(sizeof(char) * (st.st_size + 1));
    b = read(fd, s, (st.st_size + 1));
    s[b] = 0;
    return s;
}
