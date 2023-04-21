/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** players_movements.c
*/

#include "../../include/rpg.h"

int move_sprites(global_t *all)
{
    if (KEYPRESSED(sfKeyRight))
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {-0.3, 0});
    if (KEYPRESSED(sfKeyLeft))
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {0.3, 0});
    if (KEYPRESSED(sfKeyDown))
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {0, -0.3});
    if (KEYPRESSED(sfKeyUp))
        sfSprite_move(all->picture[0]->sprite, (sfVector2f) {0, 0.3});
}
