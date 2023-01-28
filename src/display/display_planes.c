/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** display_planes.c
*/
#include "../../includes/map.h"

void display_planes(map_infos *world)
{
    for (int j = 0; j < world->all_planes; j++) {
        if (world->buf_planes[j].delay <= world->radar_sec &&
            world->buf_planes[j].state == flying) {
            (world->s_pressed ? sfRenderWindow_drawSprite
                (world->window, world->buf_planes[j].sprite, NULL) : 0);
            (world->l_pressed ? sfRenderWindow_drawRectangleShape
                (world->window, world->buf_planes[j].hitbox, NULL) : 0);
        }
    }
}
