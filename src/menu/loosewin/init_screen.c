/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_screen
*/

#include "../../../include/rpg.h"

void init_lose_win(global_t *all)
{
    all->
}

void menu_loop(menu_t *menu, window_t *window, global_t *glob)
{
    int i = 0;

    init_all_menu(menu);
    sfMusic_play(menu->menu_music);
    while (sfRenderWindow_isOpen(glob->settings.window) && i == 0) {
        sfRenderWindow_clear(glob->settings.window, sfBlack);
        while (sfRenderWindow_pollEvent(glob->settings.window,\
        &window->event)) {
            menu_event_closer(menu, window, glob);
        }
        if (button_handling(menu, glob) == 2) {
            sfMusic_stop(menu->menu_music); i++;
        }
        draw_all_menu(menu, glob);
        sfRenderWindow_display(glob->settings.window);
    }
}