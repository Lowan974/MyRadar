/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-miniprintf-lowan.ferraro
** File description:
** my_putstr.c
*/
#include "../../../includes/map.h"

int my_putstr(char const *str)
{
    int counter = 0;

    while (*(str + counter) != '\0') {
        my_putchar(*(str + counter));
        counter++;
    }

    return counter;
}
