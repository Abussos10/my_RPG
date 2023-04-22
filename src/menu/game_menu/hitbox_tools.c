/*
** EPITECH PROJECT, 2023
** hitbox tools
** File description:
** hitbox_tools
*/

#include "../../../include/rpg.h"

// check if the mouse is inside a given hitbox
int check_hit(sfVector2i mouse, int corn1[], int corn2[])
{
    if (mouse.x >= corn2[0] && mouse.x <= corn2[1]) {
        if (mouse.y >= corn1[0] && mouse.y <= corn1[1])
        return (0);
    }
    return (1);
}

// function to make my buttons blinks when mouse on hit
void blink_button(g_menu *m, l_spr *sprite, char *pth)
{
    m->blink = sInit(pth);
    sfVector2f pos = GET_POS(sprite->sprite);
    sfVector2f scale_buttons = BUTTON_SCALE
    mod_sprites(m->blink->sprite, pos, scale_buttons);
    sfRenderWindow_drawSprite(m->window, m->blink->sprite, NULL);
}

// function to destroy the hover sprite if the mouse not on it
void blink_remove(g_menu *m)
{
    if (m->blink != NULL)
        free(m->blink);
}
