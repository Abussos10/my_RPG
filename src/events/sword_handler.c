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
    //printf("pos (%2.f;%2.f)\n", player_pos.x, player_pos.y);
    //pos (1472;323) pos (1633;550)
}

// function to pick the sword
void pick_the_sword(global_t *all)
{
    sfVector2f sword_scale = sfSprite_getScale(LUI->master_sword->sprite);
    //sfClock
    //sfSprite_setScale(LUI->master_sword->sprite, sword_scale);
}