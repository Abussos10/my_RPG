/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg.h
*/

#ifndef MY_H_

#pragma once
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
    #include "menu.h"

#define sfCff sfTexture_createFromFile
#define sfRWc sfRenderWindow_create
#define WIN all->settings.window
#define MODE all->settings.mode
#define SETEXT sfSprite_setTexture
#define SETSCALE sfSprite_setScale
#define SETPOS sfSprite_setPosition
#define KEYPRESSED sfKeyboard_isKeyPressed
#define BOUNDS sfSprite_getGlobalBounds

//
#define BUTTON_START
#define BUTTON_RESUME
#define BUTTON_SETTINGS
#define BUTTON_QUIT

// #define BUTTON_SETTINGS

// window structure
typedef struct window_s{
    sfVideoMode mode;
    sfEvent event;
    sfRenderWindow *window;
    sfVector2i m_p;
}window_t;
// map structure
typedef struct map_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    float speed;
} map_t;

typedef struct object_s {
    sfSprite *sprt;
    sfTexture *txt;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    char status;
} object_t;

typedef struct anim_s {
    sfClock *clk;
    sfTime time;
} anim_t;
// global structure
typedef struct global_s{
    window_t settings;
    map_t **picture;
    object_t *player;
    anim_t *clock;
} global_t;


// src/main.c :

// src/game_process.c
    int usage(int ac, char **av, global_t *all);
    void game_process(global_t *all);

// src/initialization/ :

    // init_sprites.c
    void init_scale(global_t *all);
    void init_pos(global_t *all);
    void init_setsprite(global_t *all);
    void init_sprite(global_t *all);

    // init_map.c
    void init_window(global_t *all);
    void eventclose(global_t *all);
    void screenopen(global_t *all);

// src/inventaire/ :

    // inventaire.c

// src/menu/ :
    // menu.c
    void open_main_menu(global_t *all);
// src/perso/ :
    // players_movements.c
void move_sprites(global_t *all);
int my_strlen(char *str);
int my_strcmp(char *base, char *acomp);
void eventclose(global_t *ALL);
void screenopen(global_t *ALL);
void init_window(global_t *ALL);
int usage(int ac, char **av, global_t *ALL);
void init_scale(global_t *all);
void init_pos(global_t *all);
void init_setsprite(global_t *all);
void init_sprite(global_t *all);
int menu_loop(menu_t *menu, window_t *window, global_t *glob);
void draw_all_menu(menu_t *menu, global_t *glob);
void init_sprite_menu(menu_t *menu);
void init_all_menu(menu_t *menu);
int checkbutton_play(global_t *data);
int checkbutton_quit(global_t *data, button_t *button);
void init_button(button_t *but);
int checkbutton_settings(global_t *data, button_t *button);
void init_sprite_menu(menu_t *menu);
void init_player(global_t *glob);
void left_animation(global_t *glob);
void right_animation(global_t *glob);
void unmoved_animation(global_t *glob);
void up_animation(global_t *glob);
void down_animation(global_t *glob);
void center_sprite_on_cam(global_t *all);
void map_borders_test(global_t *all);

#endif /* !MY_H_ */
