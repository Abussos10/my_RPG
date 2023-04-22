/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu
*/

#include "../../include/menu.h"
#include "../../include/rpg.h"

// function that handle the buttons
int button_handling(menu_t *menu, global_t *glob)
{
    if (checkbutton_play(glob) == 1) {
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
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfMusic_stop(menu->menu_music);
                sfRenderWindow_close(glob->settings.window);
        }
    }
    return (0);
}

// function that handle the menu loop
int menu_loop(menu_t *menu, window_t *window, global_t *glob)
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
    return (0);
}

// function that handle the close event of the menu
void menu_event_closer(menu_t *menu, window_t *window, global_t *glob)
{
    if (window->event.type == sfEvtClosed) {
        sfMusic_stop(menu->menu_music);
        sfRenderWindow_close(glob->settings.window);
    }
}
