/*
** EPITECH PROJECT, 2023
** loosewin
** File description:
** loop
*/

#include "../../../include/rpg.h"

void lose(global_t *glob, window_t *window)
{
    int i = 0;

    sfMusic_play(glob->end->m_l);
    while (sfRenderWindow_isOpen(glob->settings.window) && i == 0) {
        sfRenderWindow_clear(glob->settings.window, sfBlack);
        while (sfRenderWindow_pollEvent(glob->settings.window,\
        &window->event)) {
            menu_eventlose(glob, window);
        }
        if (button_handl(glob) == 2) {
            sfMusic_stop(glob->end->m_l); i++;
        }
        draw_lose(glob);
        sfRenderWindow_display(glob->settings.window);
    }
}

void win(global_t *glob, window_t *window)
{
    int i = 0;

    sfMusic_play(glob->end->m_w);
    while (sfRenderWindow_isOpen(glob->settings.window) && i == 0) {
        sfRenderWindow_clear(glob->settings.window, sfBlack);
        while (sfRenderWindow_pollEvent(glob->settings.window,\
        &window->event)) {
            menu_eventwin(glob, window);
        }
        if (button_handl(glob) == 2) {
            sfMusic_stop(glob->end->m_w); i++;
            sfRenderWindow_close(glob->settings.window);
        }
        draw_win(glob);
        sfRenderWindow_display(glob->settings.window);
    }
}
