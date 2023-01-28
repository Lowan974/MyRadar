/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** my_strlen.c
*/
#include "../../includes/map.h"

int my_strlen(char const *str)
{
    int count = 0 ;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}
