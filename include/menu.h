/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/GPUPreference.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdarg.h>

#pragma once

// button structure
typedef struct button_s {
    sfSprite *quit_s;
    sfTexture *quit_tx;
    sfSprite *play_s;
    sfTexture *play_tx;
    sfSprite *set_s;
    sfTexture *set_tx;
    sfSprite *bquit_s;
    sfTexture *bquit_tx;
    sfSprite *bplay_s;
    sfTexture *bplay_tx;
    sfSprite *bset_s;
    sfTexture *bset_tx;
    sfTexture *map1bw_tx;
    sfSprite *map1_s;
    sfTexture *map1_tx;
} button_t;

// menu structure
typedef struct menu_s {
    sfSprite *bg_s;
    sfTexture *bg_tx;
    sfMusic *menu_music;
    sfSprite *tx_s;
    sfTexture *tx_tx;
    button_t *but;
} menu_t;

// src/menu :

    // button.c
    int checkbutton_play(global_t *data);
    int checkbutton_settings(global_t *data, button_t *button);
    int checkbutton_quit(global_t *data, button_t *button);

    // draw.c
    void draw_all_menu(menu_t *menu, global_t *glob);

    // init_music.c
    void init_music(menu_t *menu);
    void init_all_menu(menu_t *menu);