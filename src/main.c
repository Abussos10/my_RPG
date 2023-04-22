/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include "../include/rpg.h"

int usage(int ac, char **av, global_t *all)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write(1, "\n\t    Welcome to our game rpg !\n\n", 34);
        write(1, "USAGE\n\t./my_rpg\n", 17);
        write(1, "\t my_rpg \tThe executable for the game\n\n", 40);
        write(1, "OPTIONS\n\t-h\t\tprint the usage and quit.\n\n", 41);
    } else {
        init_window(all);
        init_sprite(all);
        init_scale(all);
        init_pos(all);
        init_setsprite(all);
        init_player(all);
        all->clock->clk = sfClock_create();
    }
    return (0);
}

int main(int ac, char **av)
{
    global_t *all = malloc(sizeof(global_t));
    menu_t *menu = malloc(sizeof(menu_t));
    window_t *window = malloc(sizeof(window_t));
    menu->but = malloc(sizeof(button_t));
    all->player = malloc(sizeof(object_t));
    all->clock = malloc(sizeof(anim_t));
    usage(ac, av, all);
    if (!(all->settings.window)) return 84;
    menu_loop(menu, window, all);
    screenopen(all);
    free(all);
    return (0);
}
