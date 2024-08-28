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

char **zero(void)
{
    char **map = malloc(sizeof(char *) * 6);

    map[0] = strdup(" 000 ");
    map[1] = strdup("0   0");
    map[2] = strdup("0   0");
    map[3] = strdup("0   0");
    map[4] = strdup(" 000 ");
    map[5] = (char *)0x0;
    return map;
}

char **one(void)
{
    char **map = malloc(sizeof(char *) * 6);

    map[0] = strdup(" 000 ");
    map[1] = strdup("0 00 ");
    map[2] = strdup("  00 ");
    map[3] = strdup("  00 ");
    map[4] = strdup(" 0000");
    map[5] = (char *)0x0;
    return map;
}

char **two(void)
{
    char **map = malloc(sizeof(char *) * 6);

    map[0] = strdup(" 000 ");
    map[1] = strdup("0   0");
    map[2] = strdup("   0 ");
    map[3] = strdup(" 0   ");
    map[4] = strdup("00000");
    map[5] = (char *)0x0;
    return map;
}

char **three(void)
{
    char **map = malloc(sizeof(char *) * 6);

    map[0] = strdup("0000 ");
    map[1] = strdup("    0");
    map[2] = strdup(" 000 ");
    map[3] = strdup("    0");
    map[4] = strdup("0000 ");
    map[5] = (char *)0x0;
    return map;
}

char **four(void)
{
    char **map = malloc(sizeof(char *) * 6);

    map[0] = strdup("  00 ");
    map[1] = strdup(" 0 0 ");
    map[2] = strdup("0  0 ");
    map[3] = strdup("00000");
    map[4] = strdup("   0 ");
    map[5] = (char *)0x0;
    return map;
}
