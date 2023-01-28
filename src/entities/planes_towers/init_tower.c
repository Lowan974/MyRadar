/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** init_tower.c
*/
#include "../../../includes/map.h"

void scaning_zone(map_infos *world)
{
    for (int i = 0; i < world->all_towers; i++) {
        world->buf_towers[i].scan = create_circle
        ((sfVector2f){world->buf_towers[i].x - (world->buf_towers[i].radius / 2)
        , world->buf_towers[i].y - (world->buf_towers[i].radius / 2)},
        world->buf_towers[i].radius);
    }
}

void init_tower(map_infos *world)
{
    for (int i = 0; i < world->all_towers; i++) {
        world->buf_towers[i].sprite = create_sprite
        (world->assets.txt_towers, (sfIntRect){0, 0, 512, 512},
        (sfVector2f){0.1, 0.1}, (sfVector2f){25.6, 25.6});
    }
}
