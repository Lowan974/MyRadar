/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** destroy_elem.c
*/
#include "../../includes/map.h"

void destroy_texture(map_infos *world)
{
    sfTexture_destroy(world->assets.txt_earth);
    sfTexture_destroy(world->assets.txt_planes);
    sfTexture_destroy(world->assets.txt_towers);
    sfTexture_destroy(world->assets.txt_accel);
    sfTexture_destroy(world->assets.txt_time);
    sfTexture_destroy(world->assets.txt_menu);
    sfTexture_destroy(world->assets.txt_text_menu);
    sfClock_destroy(world->radar_clock);
    destroy_sprite(world);
    sfRenderWindow_destroy(world->window);
}

void destroy_sprite(map_infos *world)
{
    for (int i = 0; i < world->all_planes; i++) {
        sfSprite_destroy(world->buf_planes[i].sprite);
        sfRectangleShape_destroy(world->buf_planes[i].hitbox);
    }
    for (int i = 0; i < world->all_towers; i++) {
        sfSprite_destroy(world->buf_towers[i].sprite);
        sfCircleShape_destroy(world->buf_towers[i].scan);
    }
    for (int i = 0; i < CORNER_X * CORNER_Y; i++) {
        sfRectangleShape_destroy(world->zone[i].rect);
    }
    sfSprite_destroy(world->assets.start);
    sfSprite_destroy(world->assets.menu_font);
    sfSprite_destroy(world->assets.time_nb);
    sfSprite_destroy(world->assets.time_text);
    sfSprite_destroy(world->assets.time_sep);
    sfSprite_destroy(world->assets.accel_sp);
    sfSprite_destroy(world->assets.decel_sp);
    sfSprite_destroy(world->assets.earth_sp);
}

void free_elem(map_infos *world)
{
    for (int i = 0; i < CORNER_X * CORNER_Y; i++) {
        free(world->zone[i].planes);
    }
    free(world->time_sprite);
    free(world->buf_planes);
    free(world->buf_towers);
    free(world->zone);
    free(world);
}
