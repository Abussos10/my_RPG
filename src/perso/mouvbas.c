/*
** EPITECH PROJECT, 2023
** oe
** File description:
** oe
*/

#include <SFML/Graphics.h>
#include "../../include/rpg.h"

void changeSprite(sfClock* clock, sfSprite* sprite, TextureSprite* Textures)
{
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed_time) > 0.3f)
    {
        if (sfSprite_getTexture(sprite) == Textures->texture1)
            sfSprite_setTexture(sprite, Textures->texture2, sfTrue);
        if (sfSprite_getTexture(sprite) == Textures->texture2)
            sfSprite_setTexture(sprite, Textures->texture3, sfTrue);
        else
            sfSprite_setTexture(sprite, Textures->texture1, sfTrue);
        sfClock_restart(clock);
    }
}

void loadSprites(sfSprite** sprite,TextureSprite* Textures)
{
    Textures->texture1 = sfTexture_createFromFile("images/bas1.png", NULL);
    Textures->texture2 = sfTexture_createFromFile("images/bas2.png", NULL);
    Textures->texture3 = sfTexture_createFromFile("images/bas3.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, Textures->texture1, sfTrue);
}

void destroySprites(sfSprite* sprite, TextureSprite* Textures)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(Textures->texture1);
    sfTexture_destroy(Textures->texture2);
    sfTexture_destroy(Textures->texture3);
}

void checksprite(sfClock* clock, sfSprite* sprite, TextureSprite* Textures)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        changeSprite(clock, sprite, Textures);
}


void run(void)
{
    TextureSprite Textures;
    sfVideoMode mode = { 640, 480, 32 };
    sfRenderWindow* window;
    sfClock* clock;
    sfSprite* sprite;
    sfEvent event;
    float vitesse = 0.1;
    window = sfRenderWindow_create(mode, "mouvement",
        sfResize | sfClose, NULL);
    clock = sfClock_create();
    loadSprites(&sprite, &Textures);
    loadSprites2(&sprite, &Textures);
    loadSprites3(&sprite, &Textures);
    loadSprites4(&sprite, &Textures);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        checksprite(clock, sprite, &Textures); 
        checksprite2(clock, sprite, &Textures);
        checksprite3(clock, sprite, &Textures);
        checksprite4(clock, sprite, &Textures);
        deplacer_sprite(sprite, vitesse);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    destroySprites(sprite, &Textures);
    destroySprites2(sprite, &Textures);
    destroySprites3(sprite, &Textures);
    destroySprites4(sprite, &Textures);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
}