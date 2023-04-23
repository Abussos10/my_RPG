/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_music
*/

#include "../../../include/rpg.h"
#include "../../../include/menu.h"

// function that initialize the music effects
void init_music(menu_t *menu)
{
    menu->menu_music = sfMusic_createFromFile("assets/menu.ogg");
}

// function that initialize both music and sprite menu
void init_all_menu(menu_t *menu)
{
    init_music(menu);
    init_sprite_menu(menu);
}
