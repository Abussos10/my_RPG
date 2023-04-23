/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings menu
*/

#include "../../../include/rpg.h"

// function to open settings over game menu
void open_settings_menu(global_t *all, g_menu *gmenu)
{
    s_menu menu;
    all->settings_menu_state = 1;
    menu.window = all->settings.window;
    init_settings_menu_sprites(all, &menu);
    while (all->settings_menu_state == 1) {
        while (sfRenderWindow_pollEvent(menu.window, &menu.event))
            settings_menu_event(all, &menu);
        if (all->settings_menu_state == 0)
            break;
        sfRenderWindow_clear(menu.window, sfWhite);
        render_several(menu.window, 3, menu.s_menu_background,\
        menu.sound_bar, menu.sound_icon);
        s_buttons_actions(&menu, menu.window, menu.event);
        sfRenderWindow_display(menu.window);
    }
}

// function to make my button react to clicks in settings
void s_buttons_actions(s_menu *menu, sfRenderWindow *window, sfEvent event)
{

}

// function to handle events in settings menu
void settings_menu_event(global_t *all, s_menu *menu)
{
    if (menu->event.type == sfEvtKeyPressed &&
        menu->event.key.code == sfKeyEscape) {
        destroy_several(3, menu->s_menu_background, \
        menu->sound_bar, menu->sound_icon);
        all->settings_menu_state = 0;
    }
}
