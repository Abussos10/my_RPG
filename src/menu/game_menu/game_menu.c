/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu
*/

#include "../../../include/rpg.h"

// function to open menu during the game
void open_game_menu(global_t *all)
{
    g_menu menu;
    menu.pos_player = sfSprite_getPosition(all->player->sprt);
    all->game_menu_state = 1;
    menu.window = all->settings.window;
    mod_window(all, &menu);
    init_game_menu_sprites(&menu);
    while (all->game_menu_state == 1) {
        while (sfRenderWindow_pollEvent(menu.window, &menu.event))
            game_menu_event(all, &menu);
        if (all->game_menu_state == 0)
            break;
        sfRenderWindow_clear(menu.window, sfWhite);
        render_several(menu.window, 1, menu.g_menu_background);
        g_buttons_actions(all, &menu, menu.window, menu.event);
        sfRenderWindow_display(menu.window);
    }
}

// function to make my button react to clicks in game menu
void g_buttons_actions(global_t *all, g_menu *menu,\
sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int hit[4][2] = { {82, 222}, {243, 379}, {403, 542}, {562, 701} };
    int hit2[2] = {702, 1222};
    if (check_hit(mouse_pos, hit[0], hit2) == 0) {
        blink_button(menu, menu->resume, BF_RESUME);
        if (event.type == sfEvtMouseButtonPressed);
    }
    if (check_hit(mouse_pos, hit[1], hit2) == 0) {
        blink_button(menu, menu->load, BF_LOAD);
        if (event.type == sfEvtMouseButtonPressed);
    }
    if (check_hit(mouse_pos, hit[2], hit2) == 0) {
        blink_button(menu, menu->settings, BF_SETTINGS);
        if (event.type == sfEvtMouseButtonPressed);
    }
    if (check_hit(mouse_pos, hit[3], hit2) == 0) {
        blink_button(menu, menu->quit, BF_QUIT);
        if (event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(menu->window);
    }
}

// function to handle events in game menu
void game_menu_event(global_t *all, g_menu *menu)
{
    if (menu->event.type == sfEvtKeyPressed &&
        menu->event.key.code == sfKeyEscape) {
        destroy_several(1, menu->g_menu_background);
        all->game_menu_state = 0;
    }
}
