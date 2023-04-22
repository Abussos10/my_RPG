/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_sprites.c
*/

#include "../../include/rpg.h"

// function that initialize the scale of a sprite
void init_scale(global_t *all)
{
    all->picture[0]->scale = (sfVector2f) {5, 5};
    all->player->scale = (sfVector2f) {0.2, 0.2};
    LU->hotbar->scale = (sfVector2f) {1.3, 1.3};
    LU->inv_focus->scale = (sfVector2f) {0.25, 0.25};
}

// function that initialize the position of a sprite
void init_pos(global_t *all)
{
    all->picture[0]->pos = (sfVector2f) {0, 0};
    all->player->pos = (sfVector2f) {600, 300};
}

// function that set the different vector of a sprite
void init_setsprite(global_t *all)
{
    SETEXT(all->picture[0]->sprite, all->picture[0]->texture, sfTrue);
    SETSCALE(all->picture[0]->sprite, all->picture[0]->scale);
    SETPOS(all->picture[0]->sprite, all->picture[0]->pos);
}

// function that initialize a sprite
void init_sprite(global_t *all)
{
    all->picture = malloc(sizeof(map_t) * 2);
    all->picture[0] = malloc(sizeof(map_t));
    all->picture[0]->texture = sfCff("./sprites/pic/map.png", NULL);
    all->picture[0]->sprite = sfSprite_create();
    all->mask_image = sfImage_createFromFile(MASK_SPR);
    LU->hotbar = sInit(HOTBAR_SPR);
    LU->inv_focus = sInit(FOCUS_SPR);
}
