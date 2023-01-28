/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** create_functions.c
*/
#include "../../../includes/map.h"

sfSprite *create_sprite(sfTexture* texture, sfIntRect rect, sfVector2f scale,
                        sfVector2f origin)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setOrigin(sprite, origin);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 60);
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius (circle, radius);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setPosition(circle, position);
    return circle;
}
