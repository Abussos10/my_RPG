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

typedef struct window_s{
    sfVideoMode mode;
    sfEvent event;
    sfRenderWindow *window;
}window_t;

typedef struct map_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    float speed;
}map_t;

typedef struct global_s{
    window_t settings;
    map_t **picture;
}global_t;

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
void move_sprites(global_t *all);
