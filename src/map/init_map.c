/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_map.c
*/

#include "../../include/rpg.h"

void init_window(global_t *all)
{
    MODE.bitsPerPixel = 64;
    MODE.width = 1920;
    MODE.height = 1080;
    WIN = sfRenderWindow_create(MODE, "my_rpg", sfResize | sfClose, NULL);
}

void eventclose(global_t *all)
{
    if (all->settings.event.type == sfEvtClosed)
        sfRenderWindow_close(all->settings.window);
}

void screenopen(global_t *all)
{
    while (sfRenderWindow_isOpen(all->settings.window)) {
        while (sfRenderWindow_pollEvent(all->settings.window,
        &(all->settings.event))) {
            eventclose(all);
        }
        move_sprites(all);
        SETPOS(all->picture[1]->sprite, all->picture[1]->pos);
        sfRenderWindow_drawSprite(all->settings.window,
                        all->picture[0]->sprite, NULL);
        sfRenderWindow_drawSprite(all->settings.window,
                        all->picture[1]->sprite, NULL);
        sfRenderWindow_display(all->settings.window);
    }
}
