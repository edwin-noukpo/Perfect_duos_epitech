/*
** EPITECH PROJECT, 2024
** ANAGRAM
** File description:
** Function to print a character
*/

#include "../../include/utils.h"

int err_putchar(char c)
{
    write(2, &c, 1);
    return 1;
}
