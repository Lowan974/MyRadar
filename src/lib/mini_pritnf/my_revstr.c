/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-alexandre.vigneau
** File description:
** my_revstr.c
*/

#include "../../../includes/map.h"

char *my_revstr(char *str)
{
    int str_len = my_strlen(str) - 1;
    char rev_str_temp[str_len];

    for (int i = 0; *(str + i) != '\0'; i++) {
        rev_str_temp[str_len - i] = *(str + i);
    }
    for (int i = 0; i < str_len + 1; i++) {
        *(str + i) = rev_str_temp[i];
    }

    return str;
}
