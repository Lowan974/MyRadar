/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-lowan.ferraro
** File description:
** my_getnbr.c
*/

#include "../../includes/map.h"

int my_getnbr(char const *str, int arg)
{
    int i = 0; int neg = 1; long n;
    for (int x = 0; x < arg; x++) {
        while (str[i] != ' ')
            i++;
        i++;
    }
    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
            neg *= -1;
        }
        i++;
    }
    n = 0;
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    if (n > 2147483647 || n < -2147483648)
        return 0;
    return (int)(n * neg);
}
