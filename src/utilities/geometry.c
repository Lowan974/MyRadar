/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** geometry.c
*/
#include "../../includes/map.h"

float get_rotation (sfVector2f dep_pos, sfVector2f arr_pos)
{
    sfVector2f arrival = arr_pos;
    sfVector2f departure = dep_pos;
    double angle = 0;
    float origin_x = arrival.x - departure.x;
    float origin_y = arrival.y - departure.y;
    angle = atan(origin_y / origin_x) * 180 / M_PI;
    return (origin_x < 0 ? 180 + angle : angle);
}

sfVector2f calcul_direction(sfVector2f dep_pos, sfVector2f arr_pos)
{
    sfVector2f direct = {0};
    double get_move;
    float origin_x = arr_pos.x - dep_pos.x;
    float origin_y = arr_pos.y - dep_pos.y;
    float max_value =
        (fabs(origin_x) > fabs(origin_y)) ? fabs(origin_x) : fabs(origin_y);
    direct.x = origin_x / max_value;
    direct.y = origin_y / max_value;
    return (direct);
}
