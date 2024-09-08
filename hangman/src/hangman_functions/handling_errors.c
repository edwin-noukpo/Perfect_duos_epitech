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

void verif_dictionary(char **tab)
{
    int i = 0;

    while (tab[i]) {
        char **tab1 = split(tab[i], " \t");
        if (tab_len(tab1) > 1) {
            free_2d_array(tab);
            free_2d_array(tab1);
            exit(84);
        }
        free_2d_array(tab1);
        i++;
    }
    return;
}

char **dictionary(char *filepath)
{
    char *content = (char *)0x0;
    char **tab = (char **)0x0;
    int fd = fs_open_file(filepath);

    if (fd == -1)
        exit(84);
    content = read_map(fd, filepath);
    if (*content == '\0' || content == (char *)0x0) {
        free_f(content);
        exit(84);
    }
    tab = split(content, "\n");
    verif_dictionary(tab);
    free_f(content);
    return tab;
}

int win_lost(char *word_s, int tries, int count)
{
    mini_printf("%s\nTries: %d\n\n", word_s, tries);
    if (!count) {
        mini_printf("%s\nTries: %d\n\n", word_s, tries);
        my_putstr("Congratulations!\n");
        return 0;
    }
    if (!tries) {
        my_putstr("You lost!\n");
        return 0;
    }
    return 1;
}

void init_disp(char *word, char *word_s, int tries)
{
    int x = 0;

    for (int x = 1; word[x]; x++)
        word_s[x] = '*';
    mini_printf("%s\nTries: %d\n\n", word_s, tries);
    return;
}
