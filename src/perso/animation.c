/*
** EPITECH PROJECT, 2023
** my_glob
** File description:
** *
*/

#include "../../include/rpg.h"

void unmoved_animation(global_t *glob)
{
    int widthmax = 53 * 3;

    glob->player->rect.top = 0;
    glob->clock->time = sfClock_getElapsedTime(glob->clock->clk);
    if (sfTime_asMilliseconds(glob->clock->time) >= 200) {
        sfClock_restart(glob->clock->clk);
        glob->player->rect.left += 53;
        if (glob->player->rect.left >= widthmax)
            glob->player->rect.left = 0;
        sfSprite_setTextureRect(glob->player->sprt, glob->player->rect);
    }
}

void up_animation(global_t *glob)
{
    int widthmax = 53 * 10;

    glob->player->rect.top = 351;
    glob->clock->time = sfClock_getElapsedTime(glob->clock->clk);
    if (sfTime_asMilliseconds(glob->clock->time) >= 150) {
        sfClock_restart(glob->clock->clk);
        glob->player->rect.left += 53;
        if (glob->player->rect.left >= widthmax)
            glob->player->rect.left = 0;
        sfSprite_setTextureRect(glob->player->sprt, glob->player->rect);
    }
}

void left_animation(global_t *glob)
{
    int widthmax = 54 * 10;

    glob->player->rect.top = 297;
    glob->clock->time = sfClock_getElapsedTime(glob->clock->clk);
    if (sfTime_asMilliseconds(glob->clock->time) >= 150) {
        sfClock_restart(glob->clock->clk);
        glob->player->rect.left += 54;
        if (glob->player->rect.left >= widthmax)
            glob->player->rect.left = 0;
        sfSprite_setTextureRect(glob->player->sprt, glob->player->rect);
    }
}

void down_animation(global_t *glob)
{
    int widthmax = 53 * 10;

    glob->player->rect.top = 240;
    glob->clock->time = sfClock_getElapsedTime(glob->clock->clk);
    if (sfTime_asMilliseconds(glob->clock->time) >= 150) {
        sfClock_restart(glob->clock->clk);
        glob->player->rect.left += 53;
        if (glob->player->rect.left >= widthmax)
            glob->player->rect.left = 0;
        sfSprite_setTextureRect(glob->player->sprt, glob->player->rect);
    }
}

void right_animation(global_t *glob)
{
    int widthmax = 54 * 10;

    glob->player->rect.top = 410;
    glob->clock->time = sfClock_getElapsedTime(glob->clock->clk);
    if (sfTime_asMilliseconds(glob->clock->time) >= 150) {
        sfClock_restart(glob->clock->clk);
        glob->player->rect.left += 54;
        if (glob->player->rect.left >= widthmax)
            glob->player->rect.left = 0;
        sfSprite_setTextureRect(glob->player->sprt, glob->player->rect);
    }
}
