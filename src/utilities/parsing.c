/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-lowan.ferraro
** File description:
** parsing.c
*/
#include "../../includes/map.h"
static int planes_and_towers(map_infos *world, char **av);
static int init_struct(map_infos *world, char **av);

int get_size(char const *filepath, map_infos *world)
{
    int fd = 0;
    char carac;
    int size = 0;
    world->all_planes = 0;
    world->all_towers = 0;
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return -1;
    while (read(fd, &carac, 1)) {
        size++;
        world->all_planes += (carac == 'A' ? 1 : 0);
        world->all_towers += (carac == 'T' ? 1 : 0);
    }
    if (world->all_towers == 0 || world->all_planes == 0)
        return -1;
    close(fd);
    return size;
}

int get_infos(char **av, map_infos *world)
{
    int fd = 0;
    int size = get_size(av[1], world);
    if (size == -1)
        return 84;
    char *buf = malloc(sizeof(char) * (size + 1));
    if (size == -1)
        return 84;
    fd = open(av[1], O_RDONLY);
    if (read(fd, buf, size) == -1) {
        return 84;
    }
    buf[size] = '\0';
    close(fd);
    return (init_struct(world, av));
}

static int planes_and_towers(map_infos *world, char **av)
{
    char *my_infos = NULL;
    int count_a = 0;
    int count_to = 0;
    FILE *file = fopen(av[1], "r");
    size_t len = 50;
    if (file < 0)
        return 84;
    while (getline(&my_infos, &len, file) != -1) {
        if (my_infos[0] == 'A') {
            add_plane(world, &count_a, my_infos);
        }
        if (my_infos[0] == 'T') {
            world->buf_towers[count_to].x = my_getnbr(my_infos, 1);
            world->buf_towers[count_to].y = my_getnbr(my_infos, 2);
            world->buf_towers[count_to].radius = my_getnbr(my_infos, 3);
            count_to++;
        }
    }
    fclose(file);
}

static int init_struct(map_infos *world, char **av)
{
    world->time_elapsed = 0;
    world->radar_sec = 0;
    world->s_pressed = 1;
    world->l_pressed = 1;
    world->plane_destroyed = 0;
    world->accel = 1;
    world->buf_planes = malloc(sizeof(planes_infos) * world->all_planes + 1);
    world->buf_towers = malloc(sizeof(towers_infos) * world->all_towers + 1);
    planes_and_towers(world, av);
    for (int i = 0; i < world->all_planes; i++) {
        world->buf_planes[i].state = parked;
    }
    return 0;
}
