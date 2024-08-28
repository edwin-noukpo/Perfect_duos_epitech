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

int loop_handling_string(crocus_t *croc)
{
    if (croc->x + 1 < croc->ac) {
        croc->tab_string = croc->av[croc->x + 1];
        if (!*croc->tab_string)
            return special_wrtie(2, "Crocus: Empty string\n", 1);
        croc->x++;
    } else
        return special_wrtie(2, "Crocus: String is not define\n", 1);
    return 0;
}

int loop_handling_number(crocus_t *croc)
{
    if (croc->x + 1 < croc->ac) {
            croc->tab_number = croc->av[croc->x + 1];
        if (!*croc->tab_number)
            return special_wrtie(2, "Crocus: Empty number\n", 1);
        croc->x++;
    } else
        return special_wrtie(2, "Crocus: Integer is not define\n", 1);
    return 0;
}

int loop_handling(crocus_t *croc)
{
    if (!my_strcmp("-n", croc->av[croc->x])) {
        croc->nb_n++;
        if (loop_handling_number(croc))
            return 1;
    }
    if (!my_strcmp("-s", croc->av[croc->x])) {
        croc->nb_s++;
        if (loop_handling_string(croc))
            return 1;
    }
    return 0;
}

int error_handling(crocus_t *croc)
{
    for (croc->x = 1; croc->av[croc->x]; croc->x++)
        if (loop_handling(croc))
            return 1;
    if (!croc->nb_n)
        return special_wrtie(2, "Crocus: Where is the flag -n ? Read your subject please\n", 1);
    if (croc->ac == 5 && !croc->nb_s)
        return special_wrtie(2, "Crocus: Where is the flag -s ? Read your subject please\n", 1);
    for (int x = 0; croc->tab_number[x]; x++) {
        if (!is_digit(croc->tab_number[x]))
            return special_wrtie(2, "Crocus: Argument must be an integer\n", 1);
    }
    return 0;
}
