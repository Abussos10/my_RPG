/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_sprites.c
*/

#include "../include/rpg.h"

void init_scale(global_t *all)
{
    all->picture[0]->scale = (sfVector2f) {5, 5};
    all->picture[1]->scale = (sfVector2f) {0.2, 0.2};
}

void init_pos(global_t *all)
{
    all->picture[0]->pos = (sfVector2f) {0, 0};
    all->picture[1]->pos = (sfVector2f) {600, 300};
}

void init_setsprite(global_t *all)
{
    SETEXT(all->picture[0]->sprite, all->picture[0]->texture, sfTrue);
    SETSCALE(all->picture[0]->sprite, all->picture[0]->scale);
    SETPOS(all->picture[0]->sprite, all->picture[0]->pos);
    SETEXT(all->picture[1]->sprite, all->picture[1]->texture, sfTrue);
    SETSCALE(all->picture[1]->sprite, all->picture[1]->scale);
}
 
void init_sprite(global_t *all)
{
    all->picture = malloc(sizeof(map_t) * 2);
    all->picture[0] = malloc(sizeof(map_t));
    all->picture[0]->texture = sfCff("./sprites/pic/map.png", NULL);
    all->picture[0]->sprite = sfSprite_create();
    all->picture[1] = malloc(sizeof(map_t));
    all->picture[1]->texture = sfCff("./sprites/pic/megaman.png", NULL);
    all->picture[1]->sprite = sfSprite_create();
}
