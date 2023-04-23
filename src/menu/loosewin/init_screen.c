/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_screen
    */

#include "../../../include/rpg.h"

void init_screen(global_t *glob)
    {
    glob->end->l_sp = sfSprite_create();
    glob->end->l_tx = sfTexture_createFromFile("assets/lose.png", NULL);
    glob->end->w_sp = sfSprite_create();
    glob->end->w_tx = sfTexture_createFromFile("assets/win.png", NULL);
    sfSprite_setTexture(glob->end->l_sp, glob->end->l_tx, sfTrue);
    sfSprite_setTexture(glob->end->w_sp, glob->end->w_tx, sfTrue);
    sfSprite_setPosition(glob->end->l_sp, (sfVector2f) {-370, -93});
    sfSprite_setPosition(glob->end->w_sp, (sfVector2f) {-370, -93});
    sfSprite_setTexture(glob->end->l_sp, glob->end->l_tx, sfTrue);
    glob->end->b_s = sfSprite_create();
    glob->end->b_tx = sfTexture_createFromFile("assets/quit.png", NULL);
    sfSprite_setTexture(glob->end->b_s, glob->end->b_tx, sfTrue);
    sfSprite_setPosition(glob->end->b_s, (sfVector2f) {20, 50});
}

void draw_win(global_t *glob)
{
    sfRenderWindow_drawSprite(glob->settings.window, glob->end->w_sp, NULL);
    sfRenderWindow_drawSprite(glob->settings.window, glob->end->b_s, NULL);
}

void draw_lose(global_t *glob)
{
    sfRenderWindow_drawSprite(glob->settings.window, glob->end->l_sp, NULL);
    sfRenderWindow_drawSprite(glob->settings.window, glob->end->b_s, NULL);

}

void menu_eventlose(global_t *glob, window_t *window)
{
    if (window->event.type == sfEvtClosed) {
        sfMusic_stop(glob->end->m_l);
        sfRenderWindow_close(glob->settings.window);
    }
}

void menu_eventwin(global_t *glob, window_t *window)
{
    if (window->event.type == sfEvtClosed) {
        sfMusic_stop(glob->end->m_w);
        sfRenderWindow_close(glob->settings.window);
    }
}
