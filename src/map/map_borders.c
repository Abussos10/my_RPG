/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** map_borders.c
*/

#include "../../include/rpg.h"

// function that handle the map borders
void map_borders_handler(global_t *all)
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
    map_borders_handler2(all, character_bounds, background_bounds);
}

// function that handle the map borders (coding style)
void map_borders_handler2(global_t *all, sfFloatRect chr, sfFloatRect bck)
{
    if (chr.top < bck.top)
        sfSprite_setPosition(all->player->sprt,
            (sfVector2f) {chr.left, bck.top});
    if (chr.top + chr.height > bck.top
        + bck.height)
            sfSprite_setPosition(all->player->sprt,
            (sfVector2f) {chr.left, bck.top
                + bck.height - chr.height});
}

// function that center the "camera" on the sprite
void center_sprite_on_cam(global_t *all)
{
    sfRenderWindow_setView(all->settings.window, all->settings.view);
    sfView_setCenter(all->settings.view,
    sfSprite_getPosition(all->player->sprt));
}
