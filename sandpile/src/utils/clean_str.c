/*
** EPITECH PROJECT, 2024
** ok
** File description:
** clean_str
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../../include/utils.h"

clean_t *e;

int len(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

clean_t *init(char *str)
{
    e = malloc(sizeof(clean_t));
    *e = (clean_t) {0};
    e->u = len(str);
    e->new = malloc(sizeof(char) * (e->u + 1));
    return e;
}

char *clean_str_s(char *str)
{
    for (e->i = 0; str[e->i] != '\0'; e->i++) {
        if (!(str[e->i] == ' ')) {
            e->new[e->r] = str[e->i];
            e->y = 0;
            e->r += 1;
        }
        if (str[e->i] == ' ' && e->y == 0) {
            e->y = 1;
            e->new[e->r] = ' ';
            e->r++;
        }
    }
    e->new[e->r] = '\0';
    return e->new;
}

char *clean_str(char *str)
{
    if (!str) {
        err_putstr("\033[32;01mclean_str:\033[00m \
        The string is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    e = init(str);
    e->new = clean_str_s(str);
    return e->new;
}
