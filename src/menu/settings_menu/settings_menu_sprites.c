/*
** EPITECH PROJECT, 2023
** game menu sprites settings
** File description:
** game_menu_sprites
*/

#include "../../../include/rpg.h"

// modify all the sprites positions and scale
void mod_all_s_sprites(s_menu *menu)
{
    sfVector2f pos_sb = {470, 590}, scale_sb = SOUND_BAR_SCALE;
    sfVector2f pos_si = {400, 590}, scale_si = SOUND_ICON_SCALE;
    mod_sprites(menu->sound_bar->sprite, pos_sb, scale_sb);
    mod_sprites(menu->sound_icon->sprite, pos_si, scale_si);
}

// initialize the settings menu sprites
void init_settings_menu_sprites(global_t *all, s_menu *menu)
{
    menu->s_menu_background = sInit(G_MENU_BGD); 
    menu->sound_bar = sInit(SOUND_BAR);
    menu->sound_icon = sInit(SOUND_ICON);
    mod_all_s_sprites(menu);
}
