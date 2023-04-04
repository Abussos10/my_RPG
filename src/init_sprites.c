/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_sprites.c
*/

#include "../include/rpg.h"

void init_scale(global_t *all)
{
    all->picture[0]->scale = (sfVector2f) {3, 3};
    all->picture[1]->scale = (sfVector2f) {0.3, 0.3};
}

void init_pos(global_t *all)
{
    all->picture[0]->pos = (sfVector2f) {0, 0};
    all->picture[1]->pos = (sfVector2f) {400, 300};
}

void init_setsprite(global_t *all)
{
    SETEXT(all->picture[0]->sprite, all->picture[0]->texture, sfTrue);
    SETSCALE(all->picture[0]->sprite, all->picture[0]->scale);
    SETEXT(all->picture[1]->sprite, all->picture[1]->texture, sfTrue);
    SETSCALE(all->picture[1]->sprite, all->picture[1]->scale);
    //SETPOS(all->picture[1]->sprite, all->picture[1]->pos);
}

void init_sprite(global_t *all)
{
    all->picture = malloc(sizeof(map_t) * 2);
    all->picture[0] = malloc(sizeof(map_t));
    all->picture[0]->texture = sfCff("./pic/rpg_background.png", NULL);
    all->picture[0]->sprite = sfSprite_create();
    all->picture[1] = malloc(sizeof(map_t));
    all->picture[1]->texture = sfCff("./pic/megaman.png", NULL);
    all->picture[1]->sprite = sfSprite_create();
}
