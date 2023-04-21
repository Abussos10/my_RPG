/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** players_movements.c
*/

#include "../../include/rpg.h"

void move_sprites(global_t *all)
{
    if (KEYPRESSED(sfKeyRight)) {
        right_animation(all);
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {-0.3, 0});
    }
    if (KEYPRESSED(sfKeyLeft)) {
        left_animation(all);
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {0.3, 0});
    }
    if (KEYPRESSED(sfKeyDown)) {
        down_animation(all);
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {0, -0.3});
    }
    if (KEYPRESSED(sfKeyUp)) {
        up_animation(all);
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {0, 0.3});
    }
}
