/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** init_sprite.c
*/
#include "../../../includes/map.h"
static void init_textures(map_infos *world);
static void set_positions(map_infos *world);
static void init_time(map_infos *world);

void init_sprite(map_infos *world)
{
    init_textures(world);
    world->assets.earth_sp = create_sprite(world->assets.txt_earth,
    (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){1, 1}, (sfVector2f){0, 0});
    world->assets.time_nb = create_sprite(world->assets.txt_time,
    (sfIntRect){112, 0, 230, 29}, (sfVector2f){1.5, 1.5}, (sfVector2f){0, 0});
    world->assets.time_sep = create_sprite(world->assets.txt_time,
    (sfIntRect){343, 0, 14, 29}, (sfVector2f){1.5, 1.5}, (sfVector2f){0, 0});
    world->assets.accel_sp = create_sprite(world->assets.txt_accel,
    (sfIntRect){0, 0, 76, 70}, (sfVector2f){0.8, 0.8}, (sfVector2f){0, 0});
    world->assets.decel_sp = create_sprite(world->assets.txt_accel,
    (sfIntRect){0, 111, 76, 70}, (sfVector2f){0.8, 0.8}, (sfVector2f){0, 0});
    world->assets.menu_font = create_sprite(world->assets.txt_menu,
    (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){1, 1}, (sfVector2f){0, 0});
    world->assets.start = create_sprite(world->assets.txt_text_menu,
    (sfIntRect){0, 0, 357, 29}, (sfVector2f){2, 2}, (sfVector2f){0, 0});
    init_time(world); init_plane(world); init_tower(world);
    set_positions(world);
}

static void init_time(map_infos *world)
{
    world->time_sprite = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; i < 4; i++) {
        world->time_sprite[i] = world->assets.time_nb;
    }
    for (int i = 0; i < 4; i++)
        world->tab_time[i] = 0;
}

static void init_textures(map_infos *world)
{
    world->assets.txt_earth =
        sfTexture_createFromFile("ressources/world_map.png", NULL);
    world->assets.txt_planes =
        sfTexture_createFromFile("ressources/plane.png", NULL);
    world->assets.txt_towers =
        sfTexture_createFromFile("ressources/tower.png", NULL);
    world->assets.txt_time =
        sfTexture_createFromFile("ressources/time.png", NULL);
    world->assets.txt_accel =
        sfTexture_createFromFile("ressources/accel.png", NULL);
    world->assets.txt_menu =
        sfTexture_createFromFile("ressources/menu.jpg", NULL);
    world->assets.txt_text_menu =
        sfTexture_createFromFile("ressources/menu_text.png", NULL);
}

static void set_positions(map_infos *world)
{
    sfSprite_setPosition(world->assets.time_sep, (sfVector2f){1775, 20});
    sfSprite_setPosition(world->assets.accel_sp, (sfVector2f){20, 20});
    sfSprite_setPosition(world->assets.decel_sp, (sfVector2f){20, 20});
    sfSprite_setPosition(world->assets.start, (sfVector2f){640, 100});
    for (int i = 0; i < world->all_towers; i++) {
        sfSprite_setPosition(world->buf_towers[i].sprite,
            (sfVector2f){world->buf_towers[i].x, world->buf_towers[i].y});
    }
    plane_init_pos(world);
    scaning_zone(world);
}
