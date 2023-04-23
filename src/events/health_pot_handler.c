/*
** EPITECH PROJECT, 2023
** sword handler
** File description:
** sword_handler
*/

#include "../../include/rpg.h"

// function that handle the sword picking
void hpot_event_handler(global_t *all)
{
    sfVector2f player_pos = sfSprite_getPosition(all->player->sprt);
    if ((player_pos.x > 794 && player_pos.x < 1969) &&
        (player_pos.y > 893 && player_pos.y < 2067)) {
            if (KEYPRESSED(sfKeyE)) {
                pick_the_hpot(all);
                wait_for_release(sfKeyE);
                return;
            }
        }
}

// function to pick the sword
void pick_the_hpot(global_t *all)
{
    LUI->hpot_status = 1;
    LUI->health_pot->scale = (sfVector2f){0, 0};
    mod_sprites(LUI->health_pot->sprite,\
    LUI->health_pot->pos, LUI->health_pot->scale);
}
