/*
** EPITECH PROJECT, 2024
** ANAGRAM
** File description:
** Function to print a character
*/

#include "../../include/utils.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
