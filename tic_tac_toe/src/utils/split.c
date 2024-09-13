/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to convert a string into string array
*/

#include "../../include/utils.h"

int charer(char *str, char c)
{
    int i = 0;

    for (; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int line_count(char *str, char *seg)
{
    int i = 0;
    int j = 0;

    while (str[i]) {
        for (; str[i] && charer(seg, str[i]); i++);
        if (str[i] && !charer(seg, str[i]))
            j++;
        for (; str[i] && !charer(seg, str[i]); i++);
    }
    return j;
}

char **split_s(char *str, char *seg)
{
    int ln = line_count(str, seg);
    char **tab = malloc(sizeof(char *) * (ln + 1));
    split_t cut = (split_t){0, 0, 0, 0, 0};

    for (; cut.i < ln; cut.i++) {
        for (; charer(seg, str[cut.k]) && str[cut.k]; cut.k++);
        cut.a = 0;
        cut.b = cut.k;
        for (; !charer(seg, str[cut.k]) && str[cut.k]; cut.k++)
            cut.a++;
        tab[cut.i] = malloc(sizeof(char) * (cut.a + 1));
        for (cut.j = 0; cut.j < cut.a; cut.j++) {
            tab[cut.i][cut.j] = str[cut.b];
            cut.b++;
        }
        tab[cut.i][cut.j] = 0;
    }
    tab[cut.i] = 0;
    return tab;
}

char **split(char *str, char *seg)
{
    if (!str) {
        err_putstr("\033[32;01msplit:\033[00m \
        The str is \033[34;01mNULL\033[00m\n");
        return (char **)0x0;
    }
    if (!seg) {
        err_putstr("\033[32;01msplit:\033[00m \
        The seg is \033[34;01mNULL\033[00m\n");
        return (char **)0x0;
    }
    return split_s(str, seg);
}
