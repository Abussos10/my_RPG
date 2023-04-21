/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** map_borders.c
*/

#include "../../include/rpg.h"

void map_borders_test(global_t *all)
{
    sfFloatRect character_bounds = BOUNDS(all->picture[1]->sprite);
    sfFloatRect background_bounds = BOUNDS(all->picture[0]->sprite);
    if (character_bounds.left < background_bounds.left)
        sfSprite_setPosition(all->picture[1]->sprite,
        (sfVector2f) {background_bounds.left, character_bounds.top});
    if (character_bounds.left + character_bounds.width > background_bounds.left
        + background_bounds.width)
        sfSprite_setPosition(all->picture[1]->sprite,
            (sfVector2f) {background_bounds.left + background_bounds.width
                - character_bounds.width, character_bounds.top});
    if (character_bounds.top < background_bounds.top)
        sfSprite_setPosition(all->picture[1]->sprite,
            (sfVector2f) {character_bounds.left, background_bounds.top});
    if (character_bounds.top + character_bounds.height > background_bounds.top
        + background_bounds.height)
            sfSprite_setPosition(all->picture[1]->sprite,
            (sfVector2f) {character_bounds.left, background_bounds.top
                + background_bounds.height - character_bounds.height});
}

void center_sprite_on_cam(global_t *all)
{
    sfVector2u windowSize = sfRenderWindow_getSize(all->settings.window);
    sfVector2f spritePos = sfSprite_getPosition(all->picture[1]->sprite);
    if (spritePos.x < 0)
        spritePos.x = 0;
    if (spritePos.x + 791 > windowSize.x)
        spritePos.x = windowSize.x - 791;
    if (spritePos.y < 0)
        spritePos.y = 0;
    if (spritePos.y + 575 > windowSize.y)
        spritePos.y = windowSize.y - 575;
    sfSprite_setPosition(all->picture[1]->sprite, spritePos);
}