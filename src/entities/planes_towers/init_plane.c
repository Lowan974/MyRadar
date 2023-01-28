/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** init_plane.c
*/
#include "../../../includes/map.h"
static sfRectangleShape *create_hitbox(sfVector2f position, float angle,
                                sfFloatRect outline);
static sfSprite *create_plane(sfTexture* texture, sfIntRect rect,
                        sfVector2f scale, float angle);

void init_plane(map_infos *world)
{
    float angle = 0; double get_move;
    for (int i = 0; i < world->all_planes; i++) {
        get_move = (double)world->buf_planes[i].speed / (double)FRAMERATE;
        world->buf_planes[i].direction.x += get_move;
        world->buf_planes[i].direction.y += get_move;
        angle = get_rotation
        (world->buf_planes[i].departure, world->buf_planes[i].arrival);
        world->buf_planes[i].direction = calcul_direction
        (world->buf_planes[i].departure, world->buf_planes[i].arrival);
        world->buf_planes[i].sprite = create_plane(world->assets.txt_planes,
        (sfIntRect){0, 0, 285, 268}, (sfVector2f){1 / 14.25, 1 / 13.4}, angle);
        world->buf_planes[i].hitbox = create_hitbox((sfVector2f)
        {world->buf_planes[i].departure.x, world->buf_planes[i].departure.y},
            angle, world->buf_planes[i].rect);
        world->buf_planes[i].rect.width = 20;
        world->buf_planes[i].rect.height = 20;
        world->buf_planes[i].rect.left = world->buf_planes[i].departure.x;
        world->buf_planes[i].rect.top = world->buf_planes[i].departure.y;
    }
}

void plane_init_pos(map_infos *world)
{
    for (int i = 0; i < world->all_planes; i++) {
        sfSprite_setPosition(world->buf_planes[i].sprite,
            (sfVector2f){world->buf_planes[i].departure.x,
            world->buf_planes[i].departure.y});
    }
}

static sfRectangleShape *create_hitbox(sfVector2f position, float angle,
                                sfFloatRect outline)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    outline.left = position.x; outline.top = position.y;
    outline.height = 20; outline.width = 20;
    sfRectangleShape_setRotation(hitbox, angle);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 1);
    sfRectangleShape_setOutlineColor(hitbox, sfYellow);
    sfRectangleShape_setSize
        (hitbox, (sfVector2f){outline.height, outline.width});
    sfRectangleShape_setPosition
        (hitbox, (sfVector2f){outline.left, outline.top});
    return (hitbox);
}

static sfSprite *create_plane(sfTexture* texture, sfIntRect rect,
                        sfVector2f scale, float angle)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f sprite_center = {(285 * 0.1) * 0.5, (268 * 0.1) * 0.5};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setOrigin(sprite, sprite_center);
    sfSprite_setRotation(sprite, angle);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

void add_plane(map_infos *world, int *count_a, char *my_infos)
{
    world->buf_planes[*count_a].departure.x = my_getnbr(my_infos, 1);
    world->buf_planes[*count_a].departure.y = my_getnbr(my_infos, 2);
    world->buf_planes[*count_a].arrival.x = my_getnbr(my_infos, 3);
    world->buf_planes[*count_a].arrival.y = my_getnbr(my_infos, 4);
    world->buf_planes[*count_a].speed = my_getnbr(my_infos, 5);
    world->buf_planes[*count_a].delay = my_getnbr(my_infos, 6);
    *count_a += 1;
}
