/*
** EPITECH PROJECT, 2023
** game menu sprites settings
** File description:
** game_menu_sprites
*/

#include "../../../include/rpg.h"

// modify the window settings
void mod_window(global_t *all, g_menu *menu)
{
    menu->window = all->settings.window;
    sfVector2u settings = sfRenderWindow_getSize(WIN);
    menu->mode.height = settings.y; menu->mode.width = settings.x;
    menu->mode.bitsPerPixel = 64;
}
