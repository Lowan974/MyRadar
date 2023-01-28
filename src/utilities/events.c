/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** events.c
*/
#include "../../includes/map.h"

void key_pressed(sfEvent event, map_infos *world)
{
    switch (event.key.code) {
        case sfKeyL:
            world->l_pressed = (world->l_pressed == 0 ? 1 : 0);
            break;
        case sfKeyS:
            world->s_pressed = (world->s_pressed == 0 ? 1 : 0);
            break;
        case sfKeyA:
            if (world->accel > 1)
                world->accel -= (world->accel == 1 ? 3 : 1);
            break;
        case sfKeyZ:
            if (world->accel < 4)
                world->accel += (world->accel == -2 ? 3 : 1);
            break;
        default:
            break;
    }
}

void analyse_events(sfEvent event, map_infos *world)
{
    while (sfRenderWindow_pollEvent(world->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(world->window);
        }
        if (event.type == sfEvtKeyPressed && !world->game_started) {
            world->game_started = (event.key.code == sfKeySpace ? 1 : 0);
        }
        if (event.type == sfEvtKeyPressed && world->game_started)
            key_pressed(event, world);
    }
}
