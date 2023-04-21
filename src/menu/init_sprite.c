/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_sprite
*/

#include "../../include/menu.h"
#include "../../include/rpg.h"

void init_button(button_t *but)
{
    but->play_tx = sfTexture_createFromFile("assets/play.png", NULL);
    but->play_s = sfSprite_create();
    sfSprite_setTexture(but->play_s, but->play_tx, sfTrue);
    but->quit_tx = sfTexture_createFromFile("assets/quit.png", NULL);
    but->quit_s = sfSprite_create();
    sfSprite_setTexture(but->quit_s, but->quit_tx, sfTrue);
    but->set_tx = sfTexture_createFromFile("assets/settings.png", NULL);
    but->set_s = sfSprite_create();
    sfSprite_setTexture(but->set_s, but->set_tx, sfTrue);
    sfSprite_setPosition(but->play_s, (sfVector2f){350, 450});
    sfSprite_setPosition(but->set_s, (sfVector2f){500, 600});
    sfSprite_setPosition(but->quit_s, (sfVector2f){750, 750});
}

void init_button_blur(button_t *but)
{
    but->bplay_tx = sfTexture_createFromFile("assets/play_d.png", NULL);
    but->bplay_s = sfSprite_create();
    sfSprite_setTexture(but->bplay_s, but->bplay_tx, sfTrue);
    but->bquit_tx = sfTexture_createFromFile("assets/quit_d.png", NULL);
    but->bquit_s = sfSprite_create();
    sfSprite_setTexture(but->bquit_s, but->bquit_tx, sfTrue);
    but->bset_tx = sfTexture_createFromFile("assets/settings_d.png", NULL);
    but->bset_s = sfSprite_create();
    sfSprite_setTexture(but->bset_s, but->bset_tx, sfTrue);
    sfSprite_setPosition(but->bplay_s, (sfVector2f){350, 450});
    sfSprite_setPosition(but->bset_s, (sfVector2f){500, 600});
    sfSprite_setPosition(but->bquit_s, (sfVector2f){750, 750});
}

void init_sprite_menu(menu_t *menu)
{
    menu->bg_tx = sfTexture_createFromFile("assets/menu.jpg", NULL);
    menu->bg_s = sfSprite_create();
    sfSprite_setTexture(menu->bg_s, menu->bg_tx, sfTrue);
    init_button(menu->but);
    init_button_blur(menu->but);
}
