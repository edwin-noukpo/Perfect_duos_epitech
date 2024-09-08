/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** mini_printf.c
*/

#include "../../include/utils.h"

int err_cond(va_list ap, const char *format, int y)
{
    if (format[y] == '%' && format[y + 1] == '%')
        err_putchar('%');
    if (format[y] == '%' && format[y + 1] == 'd' || format[y + 1] == 'i')
        err_putnbr(va_arg(ap, int));
    if (format[y] == '%' && format[y + 1] == 's')
        err_putstr(va_arg(ap, char *));
    if (format[y] == '%' && format[y + 1] == 'c')
        err_putchar(va_arg(ap, int));
}

int err_mini_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int y = 0; format[y]; y++)
        if (format[y] != '%') {
            err_putchar(format[y]);
        } else {
            err_cond(ap, format, y);
            y++;
        }
    va_end(ap);
    return 0;
}
