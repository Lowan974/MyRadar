/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-pushswap-lowan.ferraro
** File description:
** main.c
*/
#include "../includes/map.h"
static int usage(int ac, char **av);

int main (int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (usage(ac, av) == 1)
        return 0;
    map_infos *world = malloc(sizeof(map_infos));
    world->size_w = (sfVector2i){1920, 1080};
    world->mode = (sfVideoMode){world->size_w.x, world->size_w.y};
    world->window =
    sfRenderWindow_create(world->mode, "My Radar", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(world->window, FRAMERATE);
    if (get_infos(av, world) == 84)
        return 84;
    init_sprite(world); init_zone(world);
    display_window(world);
    destroy_texture(world); free_elem(world);
    return 0;
}

static int usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "Air traffic simulation panel\n\n", 30);
        write(1, "USAGE\n ./my_radar path_to_script\n", 33);
        write(1, " In the my_radar you will see planes departing at ", 50);
        write(1, "a given time to a position at a given speed\n", 44);
        write(1, " when the plane crosses the screen it", 37);
        write(1, "rearrange to the opposite side\n\n", 32);
        write(1, "USER INTERACTIONS\n 'L' key \t", 28);
        write(1, "enable/disable hitboxes and areas.\n", 35);
        write(1, " 'S' key\tenable/disable sprites.\n", 33);
        write(1, " 'Z' key\taccelerates the program.\n", 34);
        write (1, " 'A' key\tslow down the program.\n", 33);
        return 1;
    }
    return 0;
}
