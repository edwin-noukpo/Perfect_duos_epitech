/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** mini_printf.c
*/

#include "../../include/utils.h"

int my_cond(va_list ap, const char *format, int y)
{
    if (format[y] == '%' && format[y + 1] == '%')
        my_putchar('%');
    if (format[y] == '%' && format[y + 1] == 'd')
        my_putnbr(va_arg(ap, int));
    if (format[y] == '%' && format[y + 1] == 's')
        my_putstr(va_arg(ap, char *));
    if (format[y] == '%' && format[y + 1] == 'c')
        my_putchar(va_arg(ap, int));
}

int mini_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int y = 0; format[y]; y++)
        if (format[y] != '%')
            my_putchar(format[y]);
        else {
            my_cond(ap, format, y);
            y++;
        }
    va_end(ap);
    return 0;
}
