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
    all->picture[0]->scale = (sfVector2f){5, 5};
    all->player->scale = (sfVector2f){0.2, 0.2};
    LUI->hotbar->scale = (sfVector2f){1.3, 1.3};
    LUI->inv_focus->scale = (sfVector2f){0.25, 0.25};
    LUI->master_sword->scale = (sfVector2f){0.15, 0.15};
    LUI->sword_rock->scale = (sfVector2f){0.15, 0.15};
    LUH->empty_bar->scale = (sfVector2f){1, 1};
}

// function that initialize the position of a sprite
void init_pos(global_t *all)
{
    all->picture[0]->pos = (sfVector2f){0, 0};
    all->player->pos = (sfVector2f){600, 300};
    LUI->sword_rock->pos = (sfVector2f){1500, 460};
    LUI->master_sword->pos = (sfVector2f){1500, 350};
    mod_sprites(LUI->sword_rock->sprite, LUI->sword_rock->pos, LUI->sword_rock->scale);
    mod_sprites(LUI->master_sword->sprite, LUI->master_sword->pos, LUI->master_sword->scale);
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
    LUI->hotbar = sInit(HOTBAR_SPR); LUI->inv_focus = sInit(FOCUS_SPR);
    LUI->master_sword = sInit(MASTER_SWORD); LUI->sword_rock = sInit(ROCK_SWORD);
    LUH->empty_bar = sInit(EMPTY_H);
    LUH->heart[0] = sInit(HEART); LUH->heart[1] = sInit(HEART);
    LUH->heart[2] = sInit(HEART);
}
