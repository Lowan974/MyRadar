/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** map.h
*/

#pragma once
    #include "entities.h"

    #include <SFML/Audio.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <unistd.h>
    #include <time.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <math.h>
    #include <stdarg.h>

    typedef struct map_corner{
        sfFloatRect area;
        unsigned int nb_planes;
        unsigned int nb_towers;
        planes_infos **planes;
        towers_infos *towers;
        sfRectangleShape *rect;
    }corner;

    typedef struct {
        //window
        sfRenderWindow *window;
        sfVector2i size_w;
        sfVideoMode mode;
        corner *zone;
        sfClock *radar_clock;
        sfTime radar_time;
        int radar_sec;
        int time_elapsed;
        int game_started;
        int plane_destroyed;

        //key_pressed
        int s_pressed;
        int l_pressed;
        int accel;

        //entities
        unsigned int all_planes;
        unsigned int all_towers;
        towers_infos *buf_towers;
        planes_infos *buf_planes;

        //time
        int tab_time[9];
        sfSprite **time_sprite;

        ressources assets;
    }map_infos;

    //Colisions//
        //colisions_planes//
        void colisions_planes_towers(map_infos *world);
        void colisions_between_planes(map_infos *world);
        //planes_scanning_zone//
        void colision_plane_zone(map_infos *world);

    //Display//
        //display_planes//
        void display_planes(map_infos *world);
        //display_score//
        void print_score(map_infos *world);
        //display_sprite//
        void display_map(map_infos *world);
        //display_towers//
        void display_tower(map_infos *world);
        //display_window//
        void display_window(map_infos *world);
        //display_accel//
        void display_accel(map_infos *world);

    //Entities//
        //init_entities//
        sfSprite *create_sprite(sfTexture* texture, sfIntRect rect,
            sfVector2f scale, sfVector2f origin);
        sfCircleShape *create_circle(sfVector2f position, float radius);
        void init_sprite(map_infos *world);
        void init_zone(map_infos *world);
        void check_zone(map_infos *world);
        //planes//
        void init_plane(map_infos *world);
        void plane_init_pos(map_infos *world);
        void move_plane(map_infos *world, int i);
        int out_of_map(map_infos *world, sfVector2f actual_pos, int i);
        void get_plane_pos(map_infos *world);
        int check_plane (map_infos *world, int i, int j, int x);
        void add_plane(map_infos *world, int *count_a, char *my_infos);
        //tower//
        void scaning_zone(map_infos *world);
        void init_tower(map_infos *world);

    //Lib//
    void print_framerate(void);
    int my_strlen(char const *str);
    int my_getnbr(char const *str, int arg);
    //mini_printf//
    int mini_printf (const char * format, ...);
    void my_putchar(char c);
    int my_putnbr_lli(long long int nb);
    int my_putnbr(long int nb);
    int my_putstr(char const *str);
    char *my_revstr(char *str);

    //Utilities//
        //events//
        void key_pressed(sfEvent event, map_infos *world);
        void analyse_events(sfEvent event, map_infos *world);
        //geometry//
        float get_rotation (sfVector2f dep_pos, sfVector2f arr_pos);
        sfVector2f calcul_direction(sfVector2f dep_pos, sfVector2f arr_pos);
        //parsing//
        int get_infos(char **av, map_infos *world);
        //destroy_elem//
        void free_elem(map_infos *world);
        void destroy_sprite(map_infos *world);
        void destroy_texture(map_infos *world);

    #define CORNER_X 6
    #define CORNER_Y 6
    #define FRAMERATE 60
    #define PLANE_NOT_DESTROYED(y) \
        if (world->zone[x].planes[y]->state == destroyed) \
                continue;
