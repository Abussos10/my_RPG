/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-dorian.aubry
** File description:
** init_sprite
*/

#include "../../include/rpg.h"

void init_player(global_t *glob)
{
    glob->player->sprt = sfSprite_create();
    glob->player->txt = sfTexture_createFromFile("sprites/pic/zelda.png", NULL);
    sfSprite_setTexture(glob->player->sprt, glob->player->txt, sfTrue);
    glob->player->rect = (sfIntRect){0, 0, 53, 52};
    sfSprite_setTextureRect(glob->player->sprt, glob->player->rect);
    glob->player->pos = (sfVector2f){41 * 16, 34 * 16};
    sfSprite_setPosition(glob->player->sprt, glob->player->pos);
}
