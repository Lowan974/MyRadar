/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** init_zone.c
*/
#include "../../../includes/map.h"
static void plane_in_zone(map_infos *world, int i, int j, int *count);
static sfBool point_in_zone(sfVector2f size, int i, int j, map_infos *world);

static sfRectangleShape *create_zone_rect(sfVector2f position,
    sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setSize
        (rect, size);
    sfRectangleShape_setPosition
        (rect, (sfVector2f){position.x, position.y});
    return (rect);
}

void init_zone(map_infos *world)
{
    world->zone = malloc(sizeof(corner) * (CORNER_X * CORNER_Y));
    int count = 0;
    for (int i = 0; i < CORNER_Y; i++) {
        for (int j = 0; j < CORNER_X; j++) {
            world->zone[count].area.width = world->mode.width / CORNER_X;
            world->zone[count].area.height = world->mode.height / CORNER_Y;
            world->zone[count].area.left = j * world->zone[count].area.width;
            world->zone[count].area.top = i * world->zone[count].area.height;
            world->zone[count].rect = create_zone_rect((sfVector2f)
                {world->zone[count].area.left, world->zone[count].area.top},
                (sfVector2f){world->zone[count].area.width,
                world->zone[count].area.height});
            count++;
        }
    }
    for (int x = 0; x < CORNER_X * CORNER_Y; x++) {
        world->zone[x].planes =
            malloc(sizeof(planes_infos) * world->all_planes);
    }
    check_zone(world);
}

void check_zone(map_infos *world)
{
    int count = 0;
    for (int i = 0; i < (CORNER_X * CORNER_Y); i++) {
        world->zone[i].nb_planes = 0;
    }
    for (int i = 0; i < world->all_planes; i++) {
        for (int j = 0; j < CORNER_X * CORNER_Y; j++) {
            plane_in_zone(world, i, j, &count);
        }
    }
}

static sfBool point_in_zone(sfVector2f size, int i, int j, map_infos *world)
{
    return (world->buf_planes[i].rect.left + size.x >= world->zone[j].area.left
        && world->buf_planes[i].rect.left + size.x <=
        world->zone[j].area.left + world->zone[j].area.width &&
        world->buf_planes[i].rect.top + size.y >= world->zone[j].area.top &&
        world->buf_planes[i].rect.top + size.y <=
        world->zone[j].area.top + world->zone[j].area.height);
}

static void plane_in_zone(map_infos *world, int i, int j, int *count)
{
    if (point_in_zone((sfVector2f){0, 0}, i, j, world) ||
        point_in_zone((sfVector2f)
        {0, world->buf_planes[i].rect.height}, i, j, world) ||
        point_in_zone((sfVector2f)
        {world->buf_planes[i].rect.width, 0}, i, j, world) ||
        point_in_zone((sfVector2f)
        {world->buf_planes[i].rect.width, world->buf_planes[i].rect.height}
        , i, j, world)) {
        world->zone[j].planes[world->zone[j].nb_planes] = &world->buf_planes[i];
        world->zone[j].nb_planes += 1;
    }
}
