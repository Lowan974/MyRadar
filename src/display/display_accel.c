/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** display_accel.c
*/
#include "../../includes/map.h"

void display_accel(map_infos *world)
{
    if (world->accel > 1) {
        if (world->radar_sec % 2 == 0)
            sfRenderWindow_drawSprite
                (world->window, world->assets.accel_sp, NULL);
    }
    if (world->accel < 0) {
        if (world->radar_sec % 2 == 0)
            sfRenderWindow_drawSprite
                (world->window, world->assets.decel_sp, NULL);
    }
}
