/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** planes_scanning_zone.c
*/
#include "../../includes/map.h"

static float scan_plane(int center_x, int center_y, float radius,
                        sfVector2f point)
{
    float x = point.x - (center_x + radius);
    float y = point.y - (center_y + radius);

    return (pow(x, 2) + pow(y, 2) <= pow(radius, 2) ? 1 : 0);
}

static int check_corner (map_infos *world, int j, int i)
{
    sfVector2f center = sfCircleShape_getPosition(world->buf_towers[j].scan);
    if (scan_plane(center.x, center.y, world->buf_towers[j].radius, (sfVector2f)
    {world->buf_planes[i].rect.left, world->buf_planes[i].rect.top}))
        return 1;
    if (scan_plane(center.x, center.y,
    world->buf_towers[j].radius, (sfVector2f){world->buf_planes[i].rect.left,
    world->buf_planes[i].rect.top + world->buf_planes[i].rect.height}))
        return 1;
    if (scan_plane(center.x, center.y,
    world->buf_towers[j].radius, (sfVector2f){world->buf_planes[i].rect.left +
    world->buf_planes[i].rect.width, world->buf_planes[i].rect.top}))
        return 1;
    if (scan_plane(center.x, center.y, world->buf_towers[j].radius, (sfVector2f)
    {world->buf_planes[i].rect.left + world->buf_planes[i].rect.width,
    world->buf_planes[i].rect.top + world->buf_planes[i].rect.height}))
        return 1;
    return 0;
}

static void colisions_with_radar(map_infos *world, int i)
{
    for (int j = 0; j < world->all_towers; j++) {
        if (world->buf_planes[i].state && check_corner(world, j, i)) {
            world->buf_planes[i].into_scanning_zone = 1;
            sfRectangleShape_setOutlineColor
                (world->buf_planes[i].hitbox, sfBlue);
            break;
        } else {
            sfRectangleShape_setOutlineColor
            (world->buf_planes[i].hitbox, sfYellow);
            world->buf_planes[i].into_scanning_zone = 0;
        }
    }
}

void colision_plane_zone(map_infos *world)
{
    for (int i = 0; i < world->all_planes; i++) {
        colisions_with_radar(world, i);
    }
}
