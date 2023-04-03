/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_map.c
*/

#include "../include/rpg.h"

void init_window(global_t *ALL)
{
    MODE.bitsPerPixel = 64;
    MODE.width = 1920;
    MODE.height = 1080;
    WIN = sfRenderWindow_create(MODE, "my_rpg", sfResize | sfClose, NULL);
}

void eventclose(global_t *ALL)
{
    if (ALL->settings.event.type == sfEvtClosed)
        sfRenderWindow_close(ALL->settings.window);
}

void screenopen(global_t *ALL)
{
    while (sfRenderWindow_isOpen(ALL->settings.window)) {
        while (sfRenderWindow_pollEvent(ALL->settings.window,
        &(ALL->settings.event))) {
            eventclose(ALL);
        }
    }
}

int usage(int ac, char **av, global_t *ALL)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write(1, "Welcome to our game rpg !\n\n", 28);
        write(1, "USAGE\n\t./my_rpg and ./my_rpg -h\n", 33);
        write(1, "\t my_rpg \tThe executable for the game\n\n", 40);
        write(1, "OPTIONS\n\t-h\t\tprint the usage and quit.\n\n", 41);
        write(1, "USER INTERACTIONS\n\t'L' key\t", 28);
        write(1, "enable/disable hitboxes and areas.\n", 36);
        write(1, "\t'S' key        enable/disable sprites.\n", 41);
    } else {
        init_window(ALL);
    }
    return 0;
}
