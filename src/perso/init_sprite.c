/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-dorian.aubry
** File description:
** init_sprite
*/

#include "../../include/my_rpg.h"

void init_sprite_mouv(global_t *glob, tex_t *tex)
{
    load_up(glob, tex);
    loadSprites2(&sprite, &Textures);
    loadSprites3(&sprite, &Textures);
    loadSprites4(&sprite, &Textures);
}

void load_up(global_t *glob, tex_t *tex)
{

}