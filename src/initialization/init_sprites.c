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
    all->mask_iso->scale = (sfVector2f){5, 5};
    all->mask_border->scale = (sfVector2f){5, 5};
    all->mask_iso->scale = (sfVector2f){5, 5};
    all->mask_border->scale = (sfVector2f){5, 5};
    all->player->scale = (sfVector2f){0.2, 0.2};
    LUI->hotbar->scale = (sfVector2f){1.3, 1.3};
    LUI->inv_focus->scale = (sfVector2f){0.25, 0.25};
    LUI->master_sword->scale = (sfVector2f){0.15, 0.15};
    LUI->sword_rock->scale = (sfVector2f){0.15, 0.15};
    LUH->empty_bar->scale = (sfVector2f){1, 1};
    LUI->health_pot->scale = (sfVector2f){0.19, 0.19};
    LUI->hreceptacle->scale = (sfVector2f){0.17, 0.17};
}

// function that initialize the position of a sprite
void init_pos(global_t *all)
{
    all->picture[0]->pos = (sfVector2f){0, 0};
    all->mask_border->pos = (sfVector2f){-2246, -1045};
    all->player->pos = (sfVector2f){600, 300};
    LUI->sword_rock->pos = (sfVector2f){1500, 460};
    LUI->master_sword->pos = (sfVector2f){1500, 350};
    LUI->health_pot->pos = (sfVector2f){837, 2000};
    LUI->hreceptacle->pos = (sfVector2f){773, 1955};
    mod_sprites(LUI->sword_rock->sprite,\
    LUI->sword_rock->pos, LUI->sword_rock->scale);
    mod_sprites(LUI->master_sword->sprite,\
    LUI->master_sword->pos, LUI->master_sword->scale);
    mod_sprites(LUI->health_pot->sprite, \
    LUI->health_pot->pos, LUI->health_pot->scale);
}

// function that set the different vector of a sprite
void init_setsprite(global_t *all)
{
    SETEXT(all->picture[0]->sprite, all->picture[0]->texture, sfTrue);
    SETPOS(all->picture[0]->sprite, all->picture[0]->pos);
    SETPOS(all->mask_border->sprite, all->mask_border->pos);
    SETPOS(LUI->health_pot->sprite, LUI->health_pot->pos);
    SETPOS(LUI->hreceptacle->sprite, LUI->hreceptacle->pos);
    SETSCALE(all->picture[0]->sprite, all->picture[0]->scale);
    SETSCALE(all->mask_iso->sprite, all->mask_iso->scale);
    SETSCALE(all->mask_border->sprite, all->mask_border->scale);
    SETSCALE(LUI->hreceptacle->sprite, LUI->hreceptacle->scale);
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
    LUI->master_sword = sInit(MASTER_SWORD);
    LUI->sword_rock = sInit(ROCK_SWORD); LUI->hreceptacle = sInit(RECEPTACLE);
    LUI->sword_slot = sInit(SWORD_SLOT); LUI->health_pot = sInit(HEALTH_POT);
    LUH->heart[0] = sInit(HEART); LUH->heart[1] = sInit(HEART);
    LUH->heart[2] = sInit(HEART); LUH->empty_bar = sInit(EMPTY_H);
    all->mask_iso = sInit(MASK_ISO); all->mask_border = sInit(MASK_BORDER);
    init_sprite_bis(all);
}

// second function to initialize sprites
void init_sprite_bis(global_t *all)
{
    LUI->health_pot_slot = sInit(HEALTH_POT);
}
