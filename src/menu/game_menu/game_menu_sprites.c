/*
** EPITECH PROJECT, 2023
** game menu sprites settings
** File description:
** game_menu_sprites
*/

#include "../../../include/rpg.h"

// modify all the sprites positions and scale
void mod_all_m_sprites(g_menu *menu)
{
    sfVector2f pos_back = my_offset(menu->pos_player, -550, -550);
    sfVector2f scale_back = {1, 1};
    mod_sprites(menu->g_menu_background->sprite, pos_back, scale_back);
    sfColor col_back = sfSprite_getColor(menu->g_menu_background->sprite);
    col_back.a = 3.5;
    sfSprite_setColor(menu->g_menu_background->sprite, col_back);
    sfVector2f pos_resume = {700, 80}, scale_buttons = BUTTON_SCALE
    mod_sprites(menu->resume->sprite, pos_resume, scale_buttons);
    mod_sprites(menu->load->sprite,\
    my_offset(pos_resume, 0, 160), scale_buttons);
    mod_sprites(menu->settings->sprite,\
    my_offset(pos_resume, 0, 320), scale_buttons);
    mod_sprites(menu->quit->sprite,\
    my_offset(pos_resume, 0, 480), scale_buttons);
}

// initialize the game menu sprites
void init_game_menu_sprites(g_menu *menu)
{
    menu->g_menu_background = sInit(G_MENU_BGD);
    menu->resume = sInit(B_RESUME);
    menu->load = sInit(B_LOAD);
    menu->settings = sInit(B_SETTINGS);
    menu->quit = sInit(B_QUIT);
    mod_all_m_sprites(menu);
}
