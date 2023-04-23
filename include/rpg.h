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
    #define RENDER      sfRenderWindow_drawSprite
    #define sInit       my_init_sprite

// some define to handle player collisions correctly
    #define LEFT    1
    #define RIGHT   2
    #define ABOVE   3
    #define BELOW   4

// some define to access my sprites path

// Processing...
    #define BUTTON_START
    #define BUTTON_RESUME
    #define BUTTON_SETTINGS
    #define BUTTON_QUIT

// different path for sprites so it's easily modifiable
// [GAME MENU SPRITES]
    #define G_MENU_BGD      "./sprites/background/grey_background.png"

    #define B_RESUME        "./sprites/buttons/game_menu/\
    default/continue_button.png"
    #define BF_RESUME       "./sprites/buttons/game_menu/\
    blinking/blinking_continue_button.png"

    #define B_LOAD          "./sprites/buttons/game_menu/\
    default/load_button.png"
    #define BF_LOAD         "./sprites/buttons/game_menu/\
    blinking/blinking_load_button.png"

    #define B_SETTINGS      "./sprites/buttons/game_menu/\
    default/settings_button.png"
    #define BF_SETTINGS     "./sprites/buttons/game_menu/\
    blinking/blinking_settings_button.png"

    #define B_QUIT          "./sprites/buttons/game_menu/\
    default/exit_button.png"
    #define BF_QUIT         "./sprites/buttons/game_menu/\
    blinking/blinking_exit_button.png"

// [SETTINGS MENU SPRITES]
    #define S_MENU_BGD      "./sprites/background/grey_background.png"

    #define SOUND_BAR       "./sprites/buttons/settings_menu/\
    sound_bar/soundbar.png"
    #define SOUND_ICON      "./sprites/buttons/settings_menu/\
    sound_bar/soundicon.png"

// [INVENTORY SPRITES]
    #define MASK_SPR        "./sprites/pic/test/map_mask.png"
    #define HOTBAR_SPR      "./sprites/inventory/hotbar.png"
    #define FOCUS_SPR       "./sprites/inventory/green_focus.png"

// [HEART_BAR SPRITES]
    #define EMPTY_H         "./sprites/heart_bar/empty_bar.png"
    #define HEART           "./sprites/heart_bar/heart.png"

// [SWORD SPRITES]
    #define MASTER_SWORD    "./sprites/inventory/items/broken_master_sword.png"
    #define ROCK_SWORD      "./sprites/background/big_sword_rock.png"

    #define SWORD_SLOT      "./sprites/inventory/items/master_sword_slot.png"
    #define MASK_ISO        "./sprites/background/mask_iso.png"
    #define MASK_BORDER     "./sprites/background/mask_borders.png"

    #define BUTTON_SCALE        (sfVector2f){\
        0.865, 0.7\
        };
    #define SOUND_BAR_SCALE     (sfVector2f){\
        3, 2.3\
        };
    #define SOUND_ICON_SCALE    (sfVector2f){\
        0.4, 0.4\
        };
    #define S_DEFAULT           (sfVector2f){\
        1, 1\
        };

// some shortcuts
    #define LUI  all->inv
    #define LUH  all->hea

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
    sfSprite *b_sp;
    sfTexture *b_tx;
    sfVector2f b_p;
    sfVector2f b_sc;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f e_pos;
    sfVector2f e_scale;
} npc_t;

typedef struct music_s {
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buff;
}music_t;

// object structure
typedef struct object_s {
    sfSprite *sprt;
    sfTexture *txt;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f p_pos;
    int life;
    sfSound *sound;
    sfSoundBuffer *buff;
    sfSound *scr;
    sfSoundBuffer *scr_b;
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

    l_spr *sword_rock;
    l_spr *master_sword;
    l_spr *sword_slot;

    sfVector2f hotbar_pos;
    int sword_status;
    int focus_index;
} inv_t;

// struct for health bar
typedef struct health_bar_s {
    l_spr **heart;
    l_spr *empty_bar;

    int health_status;
} health_t;

// structure for my in-game menu
typedef struct game_menu {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfVector2f pos_player;
    l_spr *g_menu_background;
    l_spr *resume;
    l_spr *load;
    l_spr *settings;
    l_spr *quit;
    l_spr *blink;
} g_menu;

typedef struct loose_win_s {
    sfSprite *w_sp;
    sfSprite *l_sp;
    sfTexture *l_tx;
    sfTexture *w_tx;
    sfMusic *m_w;
    sfMusic *m_l;
    sfSprite *b_s;
    sfTexture *b_tx;
}loose_win_t;

// structure for my settings menu
typedef struct settings_menu {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;

    l_spr *s_menu_background;
    l_spr *sound_bar;
    l_spr *sound_icon;
} s_menu;

typedef struct enemy_s {
    sfSprite *sprt;
    sfTexture *txt;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f p_pos;
    sfClock *clo;
    sfTime time;
    sfClock *clo_hit;
    sfTime time_hit;
    sfClock *clo_d;
    sfTime time_d;
    int life;
    sfSprite *sprt_d;
    sfTexture *txt_d;
    sfIntRect rect_d;
    sfVector2f pos_d;
    sfVector2f scale_d;
    sfVector2f p_pos_d;
    sfClock *clo_a;
    sfTime time_f;
    sfClock *clo_hit_a;
    sfTime time_hit_a;
    sfClock *clo_f;
    sfTime time_a;

    int life_d;
}enemy_t;

// main structure
typedef struct global_s{
    window_t settings;
    map_t **picture;
    object_t *player;
    anim_t *clock;

    inv_t *inv;
    health_t *hea;

    l_spr *mask_iso;
    l_spr *mask_border;

    int game_menu_state;
    int settings_menu_state;
    sfImage *mask_image;
    music_t *music;
    enemy_t *enemy;
    loose_win_t *end;
} global_t;

// src/main.c :

// src/game_process.c
    int usage(int ac, char **av, global_t *all, menu_t *menu);
    void game_process(global_t *all);


/**********************[INITIALIZATION PROTOTYPES]****************************/

// src/initialization/ :

    // init_struct.c
    void initialize_all(global_t *all);

    // init_sprites.c
    void init_scale(global_t *all);
    void init_pos(global_t *all);
    void init_setsprite(global_t *all);
    void init_sprite(global_t *all);

    // init_tools.c
    l_spr *my_init_sprite(char *sprite_path);
    void mod_sprites(sfSprite *sprite, sfVector2f position, sfVector2f scale);
    sfVector2f my_offset(sfVector2f pos, int offsetx, int offsety);
    int render_several(sfRenderWindow *window, int count, ...);
    int destroy_several(int count, ...);

/*****************************************************************************/




/***********************[INVENTORY PROTOTYPES]********************************/

// src/inventaire/ :

    // inventaire.c
    void init_enemy(enemy_t *data);
    void fight(global_t *glob);
    void fight_d(global_t *glob);
    void enemy_animation(enemy_t *enemy, global_t *glob);
    void inventory_render(global_t *all);
    void move_focus(global_t *all);
    void wait_for_release(int key);
    void draw_several_items(global_t *all);

/*****************************************************************************/




/*************************[HEALTH PROTOTYPES]*********************************/

// src/health_bar/ :

    // health_bar.c
    void health_bar_render(global_t *all);
    void health_handler(global_t *all, sfVector2f player_pos);

/*****************************************************************************/




/***************************[HEALTH PROTOTYPES]*******************************/

// src/events/ :

    // sword_handler.c
    void sword_event_handler(global_t *all);
    void pick_the_sword(global_t *all);

/*****************************************************************************/


/****************************[MENU PROTOTYPES]********************************/

// src/menu/main_menu/
    // menu.c
    int button_handling(menu_t *menu, global_t *glob);
    void menu_loop(menu_t *menu, window_t *window, global_t *glob);
    void menu_event_closer(menu_t *menu, window_t *window, global_t *glob);

    // button.c
    int checkbutton_play(global_t *data);
    int checkbutton_settings(global_t *data, button_t *button);
    int checkbutton_quit(global_t *data, button_t *button);

    // draw.c
    void draw_all_menu(menu_t *menu, global_t *glob);

    // init_music.c
    void init_music(menu_t *menu);
    void init_all_menu(menu_t *menu);

    // init_sprite.c
    void init_button(button_t *but);
    void init_button_blur(button_t *but);
    void init_sprite_menu(menu_t *menu);


// src/menu/game_menu :

    // game_menu.c
    void open_game_menu(global_t *all);
    void g_buttons_actions(global_t *all, g_menu *menu,\
    sfRenderWindow *window, sfEvent event);
    void game_menu_event(global_t *all, g_menu *menu);

    // game_menu_sprites.c
    void init_game_menu_sprites(g_menu *menu);
    void mod_all_m_sprites(g_menu *menu);

    // game_menu_window.c
    void mod_window(global_t *all, g_menu *menu);

    // hitbox_tools.c
    int check_hit(sfVector2i mouse, int corn1[], int corn2[]);
    void blink_button(g_menu *m, l_spr *sprite, char *pth);
    void blink_remove(g_menu *m);

// src/menu/settings_menu :
    // settings_menu.c
    void open_settings_menu(global_t *all, g_menu *gmenu);
    void s_buttons_actions(s_menu *menu, sfRenderWindow *window, sfEvent event);
    void settings_menu_event(global_t *all, s_menu *menu);

    // settings_menu_sprites.c
    void init_settings_menu_sprites(global_t *all, s_menu *menu);



/*****************************************************************************/




/***********************[CHARACTER PROTOTYPES]********************************/

// src/character/ :
    // player_movements.c
    void enemy_animation_d(enemy_t *enemy, global_t *glob);
    void move_sprites(global_t *all);

    // player_collisions.c
    int check_collision(global_t *all, int direction, int offsetx, int offsety);

    // init_sprite_perso.c
    void init_player(global_t *glob);

    // animation.c
    void unmoved_animation(global_t *glob);
    void up_animation(global_t *glob);
    void left_animation(global_t *glob);
    void down_animation(global_t *glob);
    void right_animation(global_t *glob);


/*****************************************************************************/




/*****************************[MAP PROTOTYPES]********************************/

// src/map/ :
    // map_borders.c
    void map_borders_handler(global_t *all);
    void map_borders_handler2(global_t *all, sfFloatRect chr, sfFloatRect bck);
    void center_sprite_on_cam(global_t *all);

    // init_map.c
    void init_window(global_t *all);
    void eventclose(global_t *all);
    int screenopen(global_t *all);
    void init_value(global_t *all);
    void game_events(global_t *all);

/*****************************************************************************/

// some useful functions :
int my_strlen(char *str);
int my_strcmp(char *base, char *acomp);
void eventclose(global_t *ALL);
void init_scale(global_t *all);
void init_pos(global_t *all);
void init_setsprite(global_t *all);
void init_sprite(global_t *all);
void init_button(button_t *but);
void init_sprite_menu(menu_t *menu);
void left_animation(global_t *glob);
void right_animation(global_t *glob);
void unmoved_animation(global_t *glob);
void up_animation(global_t *glob);
void init_music_game(music_t *music, global_t *glob);
void draw_npc(npc_t *npc, global_t *all);
void down_animation(global_t *glob);
void init_npc(npc_t *npc);
int init_meeting_zone(object_t *play);
void init_npc_bulle(npc_t *npc);
void init_sound(music_t *music, object_t *player);
void lose(global_t *glob, window_t *window);
void win(global_t *glob, window_t *window);
void init_screen(global_t *glob);
void menu_eventlose(global_t *glob, window_t *window);
void menu_eventwin(global_t *glob, window_t *window);
int button_handl(global_t *glob);
void draw_win(global_t *glob);
void draw_lose(global_t *glob);


#endif /* !RPG_H_ */
