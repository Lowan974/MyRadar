/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** fps.c
*/
#include "../../includes/map.h"

void print_framerate(void)
{
    static int first = 1;
    static sfClock * clock ;
    static int fps = 0;
    if (first == 1) {
        clock = sfClock_create() ;
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock) ;
    if (sfTime_asSeconds (elapsed) >= 1) {
        mini_printf("%d FPS \r", fps) ;
        fps = 0;
        sfClock_restart(clock);
    } else
        fps ++;
}
