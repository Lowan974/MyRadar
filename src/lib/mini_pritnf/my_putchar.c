/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-miniprintf-lowan.ferraro
** File description:
** my_putchar.c
*/
#include "../../../includes/map.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
