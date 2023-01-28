/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** plane.c
*/
#include "../../../includes/map.h"

void move_plane(map_infos *world, int i)
{
    int speed = 0; double get_move;
    if (world->buf_planes[i].delay <= world->radar_sec &&
        world->buf_planes[i].state != destroyed) {
        for (int j = 0; j < world->accel; j++) {
            sfSprite_move
                (world->buf_planes[i].sprite, world->buf_planes[i].direction);
            sfRectangleShape_move
                (world->buf_planes[i].hitbox, world->buf_planes[i].direction);
        }
    }
}

int out_of_map(map_infos *world, sfVector2f actual_pos, int i)
{
    if (actual_pos.x > world->size_w.x && world->buf_planes[i].state != 0) {
        world->buf_planes[i].state = destroyed;
        world->plane_destroyed += 1;
    }
    if (actual_pos.y > world->size_w.y && world->buf_planes[i].state != 0) {
        world->buf_planes[i].state = destroyed;
        world->plane_destroyed += 1;
    }
    if (actual_pos.x < 0 && world->buf_planes[i].state != 0) {
        world->buf_planes[i].state = destroyed;
        world->plane_destroyed += 1;
    }
    if (actual_pos.y < 0 && world->buf_planes[i].state != 0) {
        world->buf_planes[i].state = destroyed;
        world->plane_destroyed += 1;
    }
    return 0;
}

void get_plane_pos(map_infos *world)
{
    sfVector2f actual_pos;
    for (int i = 0; i < world->all_planes; i++) {
        actual_pos = sfSprite_getPosition(world->buf_planes[i].sprite);
        world->buf_planes[i].rect.left = actual_pos.x;
        world->buf_planes[i].rect.top = actual_pos.y;
        out_of_map(world, actual_pos, i);
    }
    colision_plane_zone(world);
    colisions_between_planes(world);
    colisions_planes_towers(world);
    display_planes(world);
}

int check_plane (map_infos *world, int i, int j, int x)
{
    if (world->zone[x].planes[i]->state == flying &&
        world->zone[x].planes[j]->state == flying &&
        world->zone[x].planes[i]->into_scanning_zone != 1 &&
        world->zone[x].planes[j]->into_scanning_zone != 1) {
            return 1;
        }
    return 0;
}
