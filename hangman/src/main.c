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
    if (!(ac == 2 || ac == 3)) {
        err_putstr("Read your project please !!!");
        return 84;
    }
    hang_man(ac, av);
    return 0;
}
