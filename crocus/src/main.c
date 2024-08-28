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
    crocus_t *croc = (crocus_t *)0x0;

    if (!(ac == 3 || ac == 5))
        return special_wrtie(2, "Read your subject please !!!\n", 84);
    croc = malloc(sizeof(crocus_t));
    *croc = (crocus_t) {ac, av, (char *)0x0, (char *)0x0, 0, 0, 1};
    if (error_handling(croc)) {
        free(croc);
        return 84;
    }
    crocus(croc->tab_number, croc->tab_string);
    free(croc);
    return 0;
}
