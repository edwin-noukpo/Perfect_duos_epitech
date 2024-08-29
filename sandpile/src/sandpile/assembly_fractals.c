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

int choose_number(sandpile_t *sand, char char_string)
{
    for (int x = 0; sand->characters_used[x]; x++)
        if (sand->characters_used[x] == char_string)
            return x;
    return 0;
}

int choose_character_s(sandpile_t *sand, int number, int x)
{
    for (int y = 0; y < sand->weight; y++)
        if (sand->sand_matrix[x][y] == number)
            return number;
    return -1;
}

char choose_character(sandpile_t *sand, int number)
{
    char character;

    for (int x = 0; x < sand->height; x++)
        if (choose_character_s(sand, number, x) >= 0)
            return sand->characters_used[number];
}

void matrix(sandpile_t *sand)
{
    sand->sand_matrix = malloc(sizeof(int *) * sand->height);
    for (int x = 0; x < sand->height; x++)
        sand->sand_matrix[x] = malloc(sizeof(int) * sand->weight);
    for (int x = 0; sand->char_matrix[x]; x++)
        for (int y = 0; sand->char_matrix[x][y]; y++)
            sand->sand_matrix[x][y] = choose_number(sand, sand->char_matrix[x][y]);
    return;
}

void replace_matrix(sandpile_t *sand)
{
    int x = 0;
    int y = 0;

    sand->char_matrix = malloc(sizeof(char *) * (sand->height + 1));
    for (int x = 0; x < sand->height; x++)
        sand->char_matrix[x] = malloc(sizeof(char) * (sand->weight + 1));
    for (x = 0; x < sand->height; x++) {
        for (y = 0; y < sand->weight; y++)
            sand->char_matrix[x][y] = choose_character(sand, sand->sand_matrix[x][y]);
        sand->char_matrix[x][y] = '\0';
    }
    sand->char_matrix[x] = (char *)0x0;
    return;
}
