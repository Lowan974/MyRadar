/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-miniprintf-lowan.ferraro
** File description:
** my_putnbr.c
*/
#include "../../../includes/map.h"

int my_putnbr(long int nb)
{
    char digits[11];
    int i = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }

    while (nb > 0) {
        digits[i] = (nb % 10) + 48;
        nb /= 10;
        ++i;
    }

    digits[i] = '\0';
    my_revstr(digits);
    my_putstr(digits);
    return i;
}
