/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-alexandre.vigneau
** File description:
** my_putnbr_lli.c
*/
#include "../../../includes/map.h"

int my_putnbr_lli(long long int nb)
{
    char digits[20];
    int i = 0;
    int neg = (nb < 0 ? 1 : 0);
    if (nb == 0) {
        my_putchar('0');
        return 1;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while (nb > 0) {
        digits[i] = (int)((nb % 10) + 48);
        nb /= 10;
        ++i;
    }
    digits[i] = '\0';
    my_revstr(digits);
    my_putstr(digits);
    return i + neg;
}
