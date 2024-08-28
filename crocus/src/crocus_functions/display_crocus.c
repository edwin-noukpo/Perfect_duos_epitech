/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/utils.h"
#include "../../include/struct.h"
#include "../../include/robot.h"
#include "../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../include/tree/tree.h"

char **get_tab_number_s(int nb)
{
    if (nb == 5)
        return five();
    if (nb == 6)
        return six();
    if (nb == 7)
        return seven();
    if (nb == 8)
        return height();
    if (nb == 9)
        return nine();
    return (char **)0x0;
}
char **get_tab_number(int nb)
{
    if (nb == 0)
        return zero();
    if (nb == 1)
        return one();
    if (nb == 2)
        return two();
    if (nb == 3)
        return three();
    if (nb == 4)
        return four();
    return get_tab_number_s(nb);
}

void display_s(char ***tab, int i)
{
    int c = three_tab_len(tab);

    for (int j = 0; j < c; j++) {
        mini_printf("%s", tab[j][i]);
        if (j < c - 1)
            mini_printf(" ");
    }
}

void display_crocus(char ***tab)
{
    for (int i = 0; i < 5; i++) {
        display_s(tab, i);
        mini_printf("\n");
    }
}
