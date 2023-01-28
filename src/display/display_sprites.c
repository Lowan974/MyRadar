/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** display_sprites.c
*/
#include "../../includes/map.h"

static void calcul_bool_print(map_infos *world)
{
    for (int i = 0; i < world->all_planes; i++) {
        if (world->buf_planes[i].delay <= world->radar_sec &&
            world->buf_planes[i].state == parked) {
            world->buf_planes[i].state = flying;
        }
    }
}

int get_accel(map_infos *world)
{
    int time = 1000000;
    if (world->accel < 0)
        time *= (world->accel * -1);
    else
        time /= world->accel;
    return time;
}

void display_map(map_infos *world)
{
    world->radar_time = sfClock_getElapsedTime(world->radar_clock);
    int time_to_sec = get_accel(world);
    if ((world->radar_time.microseconds) > time_to_sec) {
        world->radar_sec += 1; sfClock_restart(world->radar_clock);
    }
    sfRenderWindow_drawSprite(world->window, world->assets.earth_sp, NULL);
    if (world->l_pressed) {
        for (int i = 0; i < CORNER_X * CORNER_Y; i++) {
            sfRenderWindow_drawRectangleShape
                (world->window, world->zone[i].rect, NULL);
        }
    }
    print_score(world);
    check_zone(world); calcul_bool_print(world);
    display_tower(world);
    display_accel(world);
    for (int i = 0; i < world->all_planes; i++) {
        move_plane(world, i);
    }
    get_plane_pos(world);
}
