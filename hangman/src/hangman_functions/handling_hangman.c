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

int init_tries(char *nb)
{
    int tries = 10;

    if (nb)
        if (!is_integer(nb))
            tries = my_getnbr(nb);
        else
            exit(84);
    if (tries < 0)
        exit(84);
    return tries;
}

int *analyse_letter(char *line, char *word, char *word_s)
{
    int index = 0;
    int word_len = my_strlen(line);
    int *count = malloc(sizeof(int) * 2);

    count[0] = 0;
    count[1] = 1;
    for (int x = 0; word[x]; x++) {
        if (*line == word[x]) {
            word_s[x] = word[x];
            count[0]++;
        }
    }
    if (!count[0]) {
        mini_printf("'%c': is not in this word\n", *line);
        count[1] = 0;
    }
    count[0] = 0;
    for (int x = 0; word_s[x]; x++) {
        if (word_s[x] == '*')
            count[0]++;
    }
    return count;
}

void hang_man_loop(char **tab, char *word, char *word_s, int tries)
{
    int *count = 0;

    while(1) {
        char *line = retrieve_line(tab, word, word_s);
        if (!line)
            continue;
        count = analyse_letter(line, word, word_s);
        if (!count[1])
            tries--;
        if (!win_lost(word_s, tries, count[0])) {
            free_f(word);
            free_f(word_s);
            free_f(line);
            free_f(count);
            free_2d_array(tab);
            exit(0);
        }
        free_f(count);
        free_f(line);
    }
}

char *retrieve_line(char **tab, char *word, char *word_s)
{
    size_t len = 0;
    char *line = (char *)0x0;

    my_putstr("Your letter: ");
    if (getline(&line, &len, stdin) == -1) {
        free_f(word);
        free_f(word_s);
        free_f(line);
        free_2d_array(tab);
        exit(84);
    }
    if (*line == '\n') {
        free_f(line);
        return (char *)0x0;
    }
    line[my_strlen(line) - 1] = 0x0;
    if (my_strlen(line) > 1) {
        free_f(line);
        return (char *)0x0;
    }
    return line;
}

void hang_man(int ac, char **av)
{
    int tries = init_tries(av[2]);
    char **tab = dictionary(av[1]);
    char *line = (char *)0x0;
    char *word = (char *)0x0;
    char *word_s = (char *)0x0;

    srand(time(NULL));
    word = my_strdup(tab[rand() % tab_len(tab)]);
    word_s = my_strdup(word);
    init_disp(word, word_s, tries);
    hang_man_loop(tab, word, word_s, tries);
    return;
}
