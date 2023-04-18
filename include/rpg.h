/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg.h
*/

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
    #include <stddef.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdarg.h>

#define sfCff sfTexture_createFromFile
#define sfRWc sfRenderWindow_create
#define WIN all->settings.window
#define MODE all->settings.mode
#define SETEXT sfSprite_setTexture
#define SETSCALE sfSprite_setScale
#define SETPOS sfSprite_setPosition
#define KEYPRESSED sfKeyboard_isKeyPressed

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
} window_t;

// map structure
typedef struct map_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    float speed;
} map_t;

// global structure
typedef struct global_s{
    window_t settings;
    map_t **picture;
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
    int move_sprites(global_t *all);


int my_strlen(char *str);
int my_strcmp(char *base, char *acomp);