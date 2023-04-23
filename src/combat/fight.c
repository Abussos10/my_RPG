/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventaire
*/

#include "../../include/rpg.h"

void life(global_t *all)
{
    if (all->player->life != 0 && all->player->life % 5 == 0
    && all->player->life >= 5) {
        sfSound_play(all->player->sound);
        all->hea->health_status = 2;
    }
    if (all->player->life != 0 && all->player->life % 5 == 0
    && all->player->life >= 6) {
        sfSound_play(all->player->sound);
        all->hea->health_status = 1;
    }
    if (all->player->life != 0 && all->player->life % 5 == 0
    && all->player->life >= 11)
        all->hea->health_status = 0;
}

void fight(global_t *all)
{
    sfVector2f perso = sfSprite_getPosition(all->player->sprt);
    if (perso.x >= 1450 && perso.x <= 1585 &&
        perso.y >= 773 && perso.y <= 830) {
        enemy_animation(all->enemy);
        all->enemy->time_hit = sfClock_getElapsedTime(all->enemy->clo_hit);
        if (sfTime_asMilliseconds(all->enemy->time_hit) >= 1300) {
            sfClock_restart(all->enemy->clo_hit);
            all->player->life++;
            life(all);
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        sfTime_asMilliseconds(all->enemy->time_hit) >= 700) {
            all->enemy->life -= 1;
            sfSound_play(all->player->scr);
        }
    }
}
