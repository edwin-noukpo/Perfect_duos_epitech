/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to print number on stdo
*/

#include "../../include/utils.h"

int my_putnbr(int nb)
{
    if (nb >= 0 && nb <= 9)
        my_putchar(48 + nb);
    else if (nb < 0) {
        my_putchar('-');
        my_putnbr(- nb);
    } else {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    return 0;
}

int err_putnbr(int nb)
{
    if (nb >= 0 && nb <= 9)
        err_putchar(48 + nb);
    else if (nb < 0) {
        err_putchar('-');
        err_putnbr(- nb);
    } else {
        err_putnbr(nb / 10);
        err_putnbr(nb % 10);
    }
    return 0;
}
