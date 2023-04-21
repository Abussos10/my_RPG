/*
** EPITECH PROJECT, 2023
** oe
** File description:
** oe
*/

#include <SFML/Graphics.h>
#include "../../include/rpg.h"


void changeSprite4(sfClock* clock, sfSprite* sprite, TextureSprite *Textures)
{
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed_time) > 0.3f)
    {
        if (sfSprite_getTexture(sprite) == Textures->texture10)
            sfSprite_setTexture(sprite, Textures->texture11, sfTrue);
        if (sfSprite_getTexture(sprite) == Textures->texture11)
            sfSprite_setTexture(sprite, Textures->texture12, sfTrue);
        else
            sfSprite_setTexture(sprite, Textures->texture10, sfTrue);
        sfClock_restart(clock);
    }
}


void loadSprites4(sfSprite** sprite, TextureSprite *Textures)
{
    Textures->texture10 = sfTexture_createFromFile("images/gauche1.png", NULL);
    Textures->texture11 = sfTexture_createFromFile("images/gauche2.png", NULL);
    Textures->texture12 = sfTexture_createFromFile("images/gauche3.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, Textures->texture10, sfTrue);
}

void destroySprites4(sfSprite* sprite, TextureSprite *Textures)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(Textures->texture10);
    sfTexture_destroy(Textures->texture11);
    sfTexture_destroy(Textures->texture12);
}

void checksprite4(sfClock* clock, sfSprite* sprite, TextureSprite *Textures)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        changeSprite4(clock, sprite, Textures);
}