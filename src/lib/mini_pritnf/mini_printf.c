/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-miniprintf-lowan.ferraro
** File description:
** mini_printf.c
*/
#include "../../../includes/map.h"

static void my_param (va_list arguments, char format, int *count)
{
    if (format == 'd') {
        *count += my_putnbr_lli(va_arg(arguments, long long int));
    }
    if (format == 'i') {
        *count += my_putnbr(va_arg(arguments, int));
    }
    if (format == 's') {
        *count += my_putstr(va_arg(arguments, char *));
    }
    if (format == 'c') {
        my_putchar(va_arg(arguments, int));
        *count++;
    }
    if (format == '%') {
        my_putchar('%');
        *count++;
    }
}

int mini_printf (const char * format, ...)
{
    va_list arguments;
    va_start (arguments, format);
    int count = 0;

    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            count++;
        } else {
            my_param(arguments, format[i + 1], &count);
            i++;
        }
    }
    va_end(arguments);
    return count;
}
