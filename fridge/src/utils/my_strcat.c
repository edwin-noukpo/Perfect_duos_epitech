/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to concatane two strings
*/

#include "../../include/utils.h"

char *my_strcat_s(my_strcat_t *cat)
{
    cat->res_cat = malloc(sizeof(char) * (cat->index_0 + cat->index_1 + 1));
    cat->res_cat = my_strcpy(cat->res_cat, cat->src);
    while (cat->dest[cat->index_2]) {
        cat->res_cat[cat->index_1] = cat->dest[cat->index_2];
        cat->index_1++;
        cat->index_2++;
    }
    cat->res_cat[cat->index_1] = (int)0;
    return cat->res_cat;
}

char *my_strcat(char *src, char const *dest)
{
    my_strcat_t *cat = (my_strcat_t *)0x0;
    char *res_cat = (char *)0x0;

    if (!src) {
        err_putstr("\033[32;01mmy_strcat:\033[00m \
        The src is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    if (!dest) {
        err_putstr("\033[32;01mmy_strcat:\033[00m \
        The dest is \033[34;01mNULL\033[00m\n");
        return 0;
    }
    cat = malloc(sizeof(my_strcat_t));
    *cat = (my_strcat_t) {my_strlen(dest), my_strlen(src), 0, src, dest};
    res_cat = my_strcat_s(cat);
    free_f(cat);
    return res_cat;
}
