/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** Function to check if a character is a sign
*/

#include "../../include/utils.h"

int is_sign(char const c)
{
    if (c == '-' || c == '+')
        return 1;
    return 0;
}
