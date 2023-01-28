/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** display_score.c
*/
#include "../../includes/map.h"

static int nb_to_tab(int nb, int *tab)
{
    int temp;
    for (int i = 1; i < 4; i++) {
        temp = 4 - i;
        if (temp == 0 || temp == 2) {
            tab[temp] = nb % 6;
            nb = nb / 6;
        } else {
            tab[temp] = nb % 10;
            nb = nb / 10;
        }
    }
}

void print_score(map_infos *world)
{
    int print_count = 0;
    sfIntRect time_rect = (sfIntRect){112, 0, 23, 29};
    nb_to_tab(world->radar_sec, world->tab_time);
    if (world->radar_sec % 2 == 0)
        sfRenderWindow_drawSprite(world->window, world->assets.time_sep, NULL);
    for (int i = 0; i < 4; i++) {
        sfSprite_setPosition
            (world->time_sprite[i], (sfVector2f){1700 + print_count, 20});
        time_rect.left += 23 * world->tab_time[i];
        sfSprite_setTextureRect(world->time_sprite[i], time_rect);
        sfRenderWindow_drawSprite(world->window, world->time_sprite[i], NULL);
        time_rect.left = 112;
        sfSprite_setTextureRect(world->time_sprite[i], time_rect);
        print_count += (i == 1 ? 60 : 40);
    }
}
