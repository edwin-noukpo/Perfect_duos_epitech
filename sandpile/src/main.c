/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/struct.h"
#include "../include/robot.h"
#include "../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../include/tree/tree.h"

int main(int ac, char **av)
{
    sandpile_t *sand = malloc(sizeof(sandpile_t));

    *sand = (sandpile_t) {ac, av, 0, (char *)0x0, 0, 0,
    (char *)0x0, (char **)0x0, 0, 0, 0, 0, 0, 0, 0};
    if (!error_handling(sand)) {
        free_f(sand);
        return 84;
    }
    sandpile_handling(sand);
    return 0;
}
