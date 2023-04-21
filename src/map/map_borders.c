/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** map_borders.c
*/

#include "../../include/rpg.h"

void map_borders_test(global_t *all)
{
    sfFloatRect character_bounds = BOUNDS(all->player->sprt);
    sfFloatRect background_bounds = BOUNDS(all->picture[0]->sprite);
    if (character_bounds.left < background_bounds.left)
        sfSprite_setPosition(all->player->sprt,
        (sfVector2f) {background_bounds.left, character_bounds.top});
    if (character_bounds.left + character_bounds.width > background_bounds.left
        + background_bounds.width)
        sfSprite_setPosition(all->player->sprt,
            (sfVector2f) {background_bounds.left + background_bounds.width
                - character_bounds.width, character_bounds.top});
    if (character_bounds.top < background_bounds.top)
        sfSprite_setPosition(all->player->sprt,
            (sfVector2f) {character_bounds.left, background_bounds.top});
    if (character_bounds.top + character_bounds.height > background_bounds.top
        + background_bounds.height)
            sfSprite_setPosition(all->player->sprt,
            (sfVector2f) {character_bounds.left, background_bounds.top
                + background_bounds.height - character_bounds.height});
}

void center_sprite_on_cam(global_t *all)
{
    sfRenderWindow_setView(all->settings.window, all->settings.view);
    sfView_setCenter(all->settings.view,
    sfSprite_getPosition(all->player->sprt));
}