/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-dorian.aubry
** File description:
** init_enemy
*/

#include "../../include/rpg.h"

void init_enemy(enemy_t *data)
{
    data->sprt = sfSprite_create();
    data->txt = sfTexture_createFromFile("assets/chevalié.png", NULL);
    sfSprite_setTexture(data->sprt, data->txt, sfTrue);
    data->rect = (sfIntRect){0, 0, 26, 41};
    sfSprite_setScale(data->sprt, (sfVector2f) {4, 4});
    sfSprite_setTextureRect(data->sprt, data->rect);
    data->pos = (sfVector2f){1500, 700};
    sfSprite_setPosition(data->sprt, data->pos);
}
