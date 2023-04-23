/*
** EPITECH PROJECT, 2023
** sword handler
** File description:
** sword_handler
*/

#include "../../include/rpg.h"

// function that handle the sword picking
void sword_event_handler(global_t *all)
{
    sfVector2f player_pos = sfSprite_getPosition(all->player->sprt);
    if ((player_pos.x > 1472 && player_pos.x < 1633) &&
        (player_pos.y > 323 && player_pos.y < 550)) {
            if (KEYPRESSED(sfKeyE)) {
                pick_the_sword(all); return;
            }
        }
}

// function to pick the sword
void pick_the_sword(global_t *all)
{
    LUI->sword_status = 1;
    LUI->master_sword->scale = (sfVector2f){0, 0};
    mod_sprites(LUI->master_sword->sprite,\
    LUI->master_sword->pos, LUI->master_sword->scale);
}
