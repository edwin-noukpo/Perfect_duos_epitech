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

char crocus_character(char *tab_string, int nb)
{
    int len = strlen(tab_string);
    return tab_string[nb % len];
}

char change_s(char actu_letter, char new_letter)
{
    if (actu_letter == '0')
        return new_letter;
    return actu_letter;
}

char **change_letter(char **str, char letter)
{
    for (int x = 0; str[x]; x++)
        for (int y = 0; str[x][y]; y++)
            str[x][y] = change_s(str[x][y], letter);
    return str;
}

void crocus(char *tab_number, char *tab_string)
{
    char letter;
    char **temp = (char **)0x0;
    int len_number = my_strlen(tab_number);
    char ***tab_crocus = malloc(sizeof(char **) * (len_number + 1));
    int x = 0;
    int nb = 0;

    for (x = 0; tab_number[x]; x++) {
        nb = tab_number[x] - '0';
        temp = get_tab_number(nb);
        if (tab_string) {
            letter = crocus_character(tab_string, nb);
            temp = change_letter(temp, letter);
        }
        tab_crocus[x] = temp;
    }
    tab_crocus[x] = (char **)0x0;
    display_crocus(tab_crocus);
    free_3d_array(tab_crocus);
}
