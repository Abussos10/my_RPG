/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_music
*/

#include "../../include/menu.h"
#include "../../include/rpg.h"

void init_music(menu_t *menu)
{
    menu->menu_music = sfMusic_createFromFile("assets/menu.ogg");
}

void init_all_menu(menu_t *menu)
{
    init_music(menu);
    init_sprite_menu(menu);
}