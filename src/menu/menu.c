/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu
*/

#include "../../include/menu.h"
#include "../../include/rpg.h"

int button_handling(menu_t *menu, global_t *glob)
{
    if (checkbutton_play(glob, menu->but) == 1) {
            sfRenderWindow_drawSprite(glob->settings.window,
            menu->but->bplay_s, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return (2);
    }
    if (checkbutton_settings(glob, menu->but) == 1) {
            sfRenderWindow_drawSprite(glob->settings.window,
            menu->but->bplay_s, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            return (1);
        }
    }
    if (checkbutton_quit(glob, menu->but) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_drawSprite(glob->settings.window,
            menu->but->bplay_s, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_close(glob->settings.window);
        }
    }
    return (0);
}

int menu_loop(menu_t *menu, window_t *window, global_t *glob)
{
    int i = 0;

    init_all_menu(menu);
    sfMusic_play(menu->menu_music);
    while (sfRenderWindow_isOpen(glob->settings.window) && i == 0) {
        sfRenderWindow_clear(glob->settings.window, sfBlack);
        while (sfRenderWindow_pollEvent(glob->settings.window, &window->event)) {
            if (window->event.type == sfEvtClosed) {
                sfMusic_stop(menu->menu_music);
                sfRenderWindow_close(glob->settings.window);
            }
        }
        if (button_handling(menu, glob) == 2)
            i++;
        draw_all_menu(menu, glob);
        sfRenderWindow_display(glob->settings.window);
    }
    return (0);
}
