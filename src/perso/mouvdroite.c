/*
** EPITECH PROJECT, 2023
** oe
** File description:
** oe
*/


#include <SFML/Graphics.h>
#include "../../include/rpg.h"


void changeSprite3(sfClock* clock, sfSprite* sprite,TextureSprite *Textures)
{
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed_time) > 0.5f) {
        if (sfSprite_getTexture(sprite) == Textures->texture7)
            sfSprite_setTexture(sprite, Textures->texture8, sfTrue);
        if (sfSprite_getTexture(sprite) == Textures->texture8)
            sfSprite_setTexture(sprite, Textures->texture9, sfTrue);
        else
            sfSprite_setTexture(sprite, Textures->texture7, sfTrue);
        sfClock_restart(clock);
    }
}

void loadSprites3(sfSprite** sprite,TextureSprite *Textures)
{
    Textures->texture7 = sfTexture_createFromFile("images/droite1.png", NULL);
    Textures->texture8 = sfTexture_createFromFile("images/droite2.png", NULL);
    Textures->texture9 = sfTexture_createFromFile("images/droite3.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, Textures->texture7, sfTrue);
}

void destroySprites3(sfSprite* sprite,TextureSprite *Textures)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(Textures->texture7);
    sfTexture_destroy(Textures->texture8);
    sfTexture_destroy(Textures->texture9);
}

void checksprite3(sfClock* clock, sfSprite* sprite,TextureSprite *Textures)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        changeSprite3(clock, sprite, Textures);
}
