/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** display_window.c
*/
#include "../../includes/map.h"

void display_window(map_infos *world)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(world->window) && !world->game_started) {
        analyse_events(event, world);
        sfRenderWindow_clear(world->window, sfBlack);
        sfRenderWindow_drawSprite(world->window, world->assets.menu_font, NULL);
        sfRenderWindow_drawSprite(world->window, world->assets.start, NULL);
        sfRenderWindow_display(world->window);
    }
    world->radar_clock = sfClock_create();
    world->game_started = 1;
    while (sfRenderWindow_isOpen(world->window) &&
            world->plane_destroyed < world->all_planes) {
        analyse_events(event, world);
        sfRenderWindow_clear(world->window, sfBlack);
        display_map(world);
        sfRenderWindow_display(world->window);
        print_framerate();
    }
}
