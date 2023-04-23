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

void fight_d(global_t *all)
{
    sfVector2f perso = sfSprite_getPosition(all->player->sprt);
    if (perso.x >= 788 && perso.x <= 883 &&
        perso.y >= 1544 && perso.y <= 1613) {
        enemy_animation_d(all->enemy);
        all->enemy->time_hit_a =
        sfClock_getElapsedTime(all->enemy->clo_hit_a);
        if (sfTime_asMilliseconds(all->enemy->time_hit_a) >= 1300) {
            sfClock_restart(all->enemy->clo_hit_a);
            all->player->life++;
            life(all);
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        sfTime_asMilliseconds(all->enemy->time_hit_a) >= 700) {
            all->enemy->life_d -= 1;
            sfSound_play(all->player->scr);
        }
    }
}
