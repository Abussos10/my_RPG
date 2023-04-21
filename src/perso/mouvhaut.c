/*
** EPITECH PROJECT, 2023
** oe
** File description:
** oe
*/

#include <SFML/Graphics.h>
#include "../../include/rpg.h"


void changeSprite2(sfClock* clock, sfSprite* sprite, TextureSprite *Textures)
{
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed_time) > 0.5f) {
        if (sfSprite_getTexture(sprite) == Textures->texture4)
            sfSprite_setTexture(sprite, Textures->texture5, sfTrue);
        if (sfSprite_getTexture(sprite) == Textures->texture5)
            sfSprite_setTexture(sprite, Textures->texture6, sfTrue);
        else
            sfSprite_setTexture(sprite, Textures->texture4, sfTrue);
        sfClock_restart(clock);
    }
}

void loadSprites2(sfSprite** sprite,TextureSprite *Textures)
{
    Textures->texture4 = sfTexture_createFromFile("images/haut1.png", NULL);
    Textures->texture5 = sfTexture_createFromFile("images/haut2.png", NULL);
    Textures->texture6 = sfTexture_createFromFile("images/haut3.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, Textures->texture4, sfTrue);
}

void destroySprites2(sfSprite* sprite, TextureSprite *Textures)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(Textures->texture4);
    sfTexture_destroy(Textures->texture5);
    sfTexture_destroy(Textures->texture6);
}

void checksprite2(sfClock* clock, sfSprite* sprite, TextureSprite *Textures)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        changeSprite2(clock, sprite, Textures);
}