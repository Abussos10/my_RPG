/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-dorian.aubry
** File description:
** init_tools
*/

#include "../../include/rpg.h"

// function that does everything needed to display a sprite
l_spr *my_init_sprite(char *sprite_path)
{
    l_spr *new_sprite = malloc(sizeof(l_spr));
    new_sprite->texture = sfTexture_createFromFile(sprite_path, NULL);
    new_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(new_sprite->sprite, new_sprite->texture, sfTrue);
    return (new_sprite);
}

// function that modify the scale and position of a sprite
void mod_sprites(sfSprite *sprite, sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
}

// offset function for a sprite
sfVector2f my_offset(sfVector2f pos, int offsetx, int offsety)
{
    sfVector2f vector = {(pos.x + offsetx), (pos.y + offsety)};
    return (vector);
}

// function to render an infinite number of sprite at once
int render_several(sfRenderWindow *window, int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        l_spr *sprite = va_arg(args, l_spr *);
        sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
    }
    va_end(args);
    return (0);
}

// function to destroy an infinite number of sprite at once
int destroy_several(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        l_spr *sprite = va_arg(args, l_spr *);
        sfSprite_destroy(sprite->sprite);
    }
    va_end(args);
    return (0);
}
