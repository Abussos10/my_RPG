/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include "../include/rpg.h"

int usage(global_t *all)
{
    init_window(all);
    init_sprite(all);
    init_scale(all);
    init_pos(all);
    init_setsprite(all);
    init_player(all);
    init_npc(all->player->npc);
    init_music_game(all->music, all);
    all->clock->clk = sfClock_create();
    all->enemy->clo = sfClock_create();
    all->enemy->clo_hit = sfClock_create();
    all->enemy->clo_d = sfClock_create();
    all->player->life = 0;
    return (0);
}

int main(void)
{
    global_t *all = malloc(sizeof(global_t));
    menu_t *menu = malloc(sizeof(menu_t));
    window_t *window = malloc(sizeof(window_t));
    menu->but = malloc(sizeof(button_t));
    all->player = malloc(sizeof(object_t));
    all->clock = malloc(sizeof(anim_t));
    all->music = malloc(sizeof(music_t));
    all->player->npc = malloc(sizeof(npc_t));
    all->enemy = malloc(sizeof(enemy_t));
    usage(all);
    if (!(all->settings.window)) return 84;
    menu_loop(menu, window, all);
    initialize_all(all);
    screenopen(all);
    free(all);
    return (0);
}
