/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include "../include/rpg.h"

int usage(int ac, char **av, global_t *all)
{
    init_window(all);
    init_sprite(all);
    init_scale(all);
    init_pos(all);
    init_setsprite(all);
    init_player(all);
    init_npc(all->player->npc);
    init_music_game(all->music);
    all->clock->clk = sfClock_create();
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
    all->music = malloc(sizeof(music_t));
    all->player->npc = malloc(sizeof(npc_t));
    usage(ac, av, all);
    if (!(all->settings.window)) return 84;
    menu_loop(menu, window, all);
    screenopen(all);
    free(all);
    return (0);
}
