/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** entities.h
*/

#pragma once
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
    typedef enum state{
        destroyed,
        flying,
        parked
    }plane_state;

    typedef struct {
        sfVector2f departure;
        sfVector2f arrival;
        sfVector2f direction;
        int speed;
        int delay;
        int into_scanning_zone;
        int index;
        plane_state state;
        sfSprite *sprite;
        sfRectangleShape *hitbox;
        sfFloatRect rect;
    }planes_infos;

    typedef struct {
        int x;
        int y;
        float radius;
        sfCircleShape *scan;
        sfSprite *sprite;
    }towers_infos;

    typedef struct {
        sfTexture *txt_earth;
        sfTexture *txt_planes;
        sfTexture *txt_towers;
        sfTexture *txt_time;
        sfTexture *txt_accel;
        sfTexture *txt_menu;
        sfTexture *txt_text_menu;
        sfSprite  *menu_font;
        sfSprite *accel_sp;
        sfSprite *decel_sp;
        sfSprite *time_text;
        sfSprite *time_nb;
        sfSprite *time_sep;
        sfSprite *earth_sp;
        sfSprite *start;
    }ressources;
