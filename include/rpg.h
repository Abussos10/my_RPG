/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
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

// some define to optimize calling CSFML functions
    #define sfCff       sfTexture_createFromFile
    #define sfRWc       sfRenderWindow_create
    #define WIN         all->settings.window
    #define MODE        all->settings.mode
    #define SETEXT      sfSprite_setTexture
    #define SETSCALE    sfSprite_setScale
    #define SETPOS      sfSprite_setPosition
    #define KEYPRESSED  sfKeyboard_isKeyPressed
    #define BOUNDS      sfSprite_getGlobalBounds
    #define GET_POS     sfSprite_getPosition
    #define sInit       my_init_sprite

// some define to handle player collisions correctly
    #define LEFT    1
    #define RIGHT   2
    #define ABOVE   3
    #define BELOW   4

// some define to access my sprites path
    #define MASK_SPR "./sprites/pic/map_mask.png"
    #define HOTBAR_SPR "./sprites/pic/hotbar.png"
    #define FOCUS_SPR "./sprites/pic/green_focus.png"

// Processing...
    #define BUTTON_START
    #define BUTTON_RESUME
    #define BUTTON_SETTINGS
    #define BUTTON_QUIT

// some shortcuts
    #define LU  all->inv

// window structure
typedef struct window_s{
    sfVideoMode mode;
    sfEvent event;
    sfRenderWindow *window;
    sfVector2i m_p;
    sfView *view;
} window_t;

// map structure
typedef struct map_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    float speed;
} map_t;

typedef struct npc_s {
    sfSprite *sprt;
    sfTexture *txt;
    sfSprite *e_sp;
    sfTexture *e_tx;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
}npc_t;

typedef struct music_s {
    sfMusic *music;
}music_t;

// object structure
typedef struct object_s {
    sfSprite *sprt;
    sfTexture *txt;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    npc_t *npc;
} object_t;

// animation structure
typedef struct anim_s {
    sfClock *clk;
    sfTime time;
} anim_t;

// struct for sprites
typedef struct l_sprites {
    sfTexture *texture;
    sfSprite *sprite;

    sfVector2f scale;
    sfVector2f pos;
} l_spr;

// struct for inventory
typedef struct inventory_s {
    l_spr *hotbar;
    l_spr *inv_focus;

    int focus_index;
} inv_t;

// main structure
typedef struct global_s{
    window_t settings;
    map_t **picture;
    object_t *player;
    anim_t *clock;

    inv_t *inv;

    sfImage *mask_image;
    music_t *music;
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
    void init_value(global_t *all);

    // init_tools.c
    l_spr *my_init_sprite(char *sprite_path);
    void mod_sprites(sfSprite *sprite, sfVector2f position, sfVector2f scale);
    sfVector2f my_offset(sfVector2f pos, int offsetx, int offsety);
    int render_several(sfRenderWindow *window, int count, ...);
    int destroy_several(int count, ...);

// src/inventaire/ :

    // inventaire.c
    void inventory_render(global_t *all);
    void move_focus(global_t *all);
    void wait_for_release(int key);

// src/menu/ :
    // menu.c
    void open_main_menu(global_t *all);



// src/perso/ :
    // player_movements.c
    void move_sprites(global_t *all);

    // player_collisions.c
    int check_collision(global_t *all, int direction, int offsetx, int offsety);

    // init_sprite_perso.c
    void init_player(global_t *glob);

// src/map/ :
    // map_borders.c
    void map_borders_handler(global_t *all);
    void map_borders_handler2(global_t *all, sfFloatRect chr, sfFloatRect bck);
    void center_sprite_on_cam(global_t *all);



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

    // menu.c
    int button_handling(menu_t *menu, global_t *glob);
    int menu_loop(menu_t *menu, window_t *window, global_t *glob);
    void menu_event_closer(menu_t *menu, window_t *window, global_t *glob);

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
void init_sprite_menu(menu_t *menu);
void init_button(button_t *but);
void init_sprite_menu(menu_t *menu);
void left_animation(global_t *glob);
void right_animation(global_t *glob);
void unmoved_animation(global_t *glob);
void up_animation(global_t *glob);
void init_music_game(music_t *music);
void down_animation(global_t *glob);

#endif /* !RPG_H_ */
