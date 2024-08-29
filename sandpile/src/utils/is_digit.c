/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to check if a character is a digit
*/

#include "../../include/utils.h"

int is_digit(char c)
{
    if (!(c >= '0' && c <= '9'))
        return 0;
    return 1;
}
