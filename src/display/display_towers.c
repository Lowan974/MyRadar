/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** display_towers.c
*/
#include "../../includes/map.h"

void display_tower(map_infos *world)
{
    if (world->s_pressed) {
        for (int i = 0; i < world->all_towers; i++) {
            sfRenderWindow_drawSprite(world->window,
                        world->buf_towers[i].sprite, NULL);
        }
    }
    if (world->l_pressed) {
        for (int i = 0; i < world->all_towers; i++) {
            sfRenderWindow_drawCircleShape
                (world->window, world->buf_towers[i].scan, NULL);
        }
    }
}
