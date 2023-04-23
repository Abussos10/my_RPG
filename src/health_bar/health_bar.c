/*
** EPITECH PROJECT, 2023
** health bar handling
** File description:
** health_bar
*/

#include "../../include/rpg.h"

// function that handle my health bar
void health_bar_render(global_t *all)
{
    sfVector2f player_pos = sfSprite_getPosition(all->player->sprt);
    LUH->empty_bar->pos = my_offset(player_pos, -1150, -878);
    mod_sprites(LUH->empty_bar->sprite, LUH->empty_bar->pos, LUH->empty_bar->scale);
    for (int i = 0; i != 3; i++) {
        LUH->heart[i]->pos = my_offset(player_pos, -10000, -10000);
        mod_sprites(LUH->heart[i]->sprite, LUH->heart[i]->pos, LUH->empty_bar->scale);
    }
    health_handler(all, player_pos);
    render_several(all->settings.window, 4, LUH->empty_bar, LUH->heart[0], LUH->heart[1], LUH->heart[2]);
}

// health handler
void health_handler(global_t *all, sfVector2f player_pos)
{
    for (int i = 0; i != LUH->health_status; i++) {
        LUH->heart[i]->pos = my_offset(player_pos, -1300 + (i * 150), -878);
        mod_sprites(LUH->heart[i]->sprite, LUH->heart[i]->pos, LUH->empty_bar->scale);
    }
}