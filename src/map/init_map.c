/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_map.c
*/

#include "../../include/rpg.h"

// function to initialize the window
void init_window(global_t *all)
{
    init_value(all);
    MODE.bitsPerPixel = 64;
    MODE.width = 1920;
    MODE.height = 1080;
    WIN = sfRenderWindow_create(MODE, "my_rpg", sfResize | sfClose, NULL);
}

// event to close the game
void eventclose(global_t *all)
{
    if (all->settings.event.type == sfEvtClosed)
        sfRenderWindow_close(all->settings.window);
    if (all->settings.event.type == sfEvtKeyPressed && 
    all->settings.event.key.code == sfKeyEscape) {
        //open_game_menu(all);
    }
}

// loop of the game
void screenopen(global_t *all)
{
    all->settings.view = sfView_create();
    sfView_setSize(all->settings.view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all->settings.window, all->settings.view);
    sfMusic_play(all->music->music);
    sfMusic_setLoop(all->music->music, sfTrue);
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
        inventory_render(all); health_bar_render(all);
        sword_event_handler(all);
        draw_npc(all->player->npc, all);
        if (init_meeting_zone(all->player, all) == 1) {
            sfRenderWindow_drawSprite(all->settings.window,
            all->player->npc->b_sp, NULL);
            sfSound_play(all->music->sound);
        }
        inventory_render(all);
        sfRenderWindow_display(all->settings.window);
    }
}

// function to initialize some useful value in my struct
void init_value(global_t *all)
{
    LUI = malloc(sizeof(inv_t));
    LUH = malloc(sizeof(health_t));
    LUH->heart = malloc(sizeof(l_spr) * 2);
    LUI->focus_index = 0;
    LUH->health_status = 3;
}
