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
    all->settings.view = sfView_create();
    sfView_setSize(all->settings.view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all->settings.window, all->settings.view);

    while (sfRenderWindow_isOpen(all->settings.window)) {
        sfRenderWindow_clear(all->settings.window, sfBlack);
        while (sfRenderWindow_pollEvent(all->settings.window,
        &(all->settings.event)))
            eventclose(all);
        move_sprites(all);
        center_sprite_on_cam(all);
        map_borders_handler(all);
        sfRenderWindow_drawSprite(all->settings.window,
                        all->picture[0]->sprite, NULL);
        sfRenderWindow_drawSprite(all->settings.window,
                        all->player->sprt, NULL);
        sfRenderWindow_display(all->settings.window);
    }
}
