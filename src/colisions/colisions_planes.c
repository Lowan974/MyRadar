/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** colisions_planes.c
*/
#include "../../includes/map.h"
static void is_intersecting_hitbox(map_infos *world, int i, int x);

void colisions_planes_towers(map_infos *world)
{
    for (int x = 0; x < CORNER_X * CORNER_Y; x++) {
        for (int i = 0; i < world->zone[x].nb_planes; i++) {
            ((world->zone[x].planes[i]->state == flying &&
                (int)world->zone[x].planes[i]->arrival.x >=
                (int)world->zone[x].planes[i]->rect.left
                && (int)world->zone[x].planes[i]->arrival.x <=
                    (int)world->zone[x].planes[i]->rect.left
                + (int)world->zone[x].planes[i]->rect.width
                && (int)world->zone[x].planes[i]->arrival.y >=
                    (int)world->zone[x].planes[i]->rect.top
                && (int)world->zone[x].planes[i]->arrival.y <=
                    (int)world->zone[x].planes[i]->rect.top
                + (int)world->zone[x].planes[i]->rect.height) ?
                    world->zone[x].planes[i]->state = destroyed,
                    world->plane_destroyed += 1 : 0);
        }
    }
}

void colisions_between_planes(map_infos *world)
{
    for (int x = 0; x < CORNER_X * CORNER_Y; x++) {
        for (int i = 0; i < world->zone[x].nb_planes; i++) {
            PLANE_NOT_DESTROYED(i)
                is_intersecting_hitbox(world, i, x);
        }
    }
}

static void is_intersecting_hitbox(map_infos *world, int i, int x)
{
    for (int j = i + 1; j < world->zone[x].nb_planes; j++) {
        PLANE_NOT_DESTROYED(j)
        if (check_plane(world, i, j, x) == 1 &&
        sfFloatRect_intersects(&world->zone[x].planes[i]->rect,
                                &world->zone[x].planes[j]->rect, NULL)) {
            world->zone[x].planes[i]->state = destroyed;
            world->zone[x].planes[j]->state = destroyed;
            world->plane_destroyed += 2;
        }
    }
}
