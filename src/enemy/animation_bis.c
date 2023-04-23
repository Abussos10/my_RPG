/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-dorian.aubry
** File description:
** animation_bis
*/

#include "../../include/rpg.h"

void enemy_animation(enemy_t *enemy, global_t *glob)
{
    int widthmax = 20 * 4;
    sfVector2f perso = sfSprite_getPosition(glob->player->sprt);
    enemy->rect.top = 0;
    enemy->time = sfClock_getElapsedTime(enemy->clo);
    if (sfTime_asMilliseconds(enemy->time) >= 350) {
        sfClock_restart(enemy->clo);
        enemy->rect.left += 28;
        if (enemy->rect.left >= widthmax)
            enemy->rect.left = 0;
        sfSprite_setTextureRect(enemy->sprt, enemy->rect);
    }
}
