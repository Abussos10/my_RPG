/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventaire
*/

#include "../../include/rpg.h"

// function to render my inventory sprites 96
void inventory_render(global_t *all)
{

    sfVector2f player_pos = sfSprite_getPosition(all->player->sprt);
    LU->hotbar->pos = my_offset(player_pos, -523, 46);
    mod_sprites(LU->hotbar->sprite, LU->hotbar->pos, LU->hotbar->scale);
    sfVector2f hotbar_pos = sfSprite_getPosition(LU->hotbar->sprite);
    LU->inv_focus->pos = my_offset(hotbar_pos,\
    96 + 93.8 * LU->focus_index, 326);
    mod_sprites(LU->inv_focus->sprite,\
    LU->inv_focus->pos, LU->inv_focus->scale);
    move_focus(all);
    render_several(all->settings.window, 2, LU->hotbar, LU->inv_focus);
}

// function to handle event on my inventory (focus moves)
void move_focus(global_t *all)
{
    if (KEYPRESSED(sfKeyLShift) || KEYPRESSED(sfKeyRShift)) {
        if (KEYPRESSED(sfKeyLeft) && LU->focus_index > 0) {
            LU->focus_index -= 1; wait_for_release(sfKeyLeft); return;
        }
        if (KEYPRESSED(sfKeyRight) && LU->focus_index < 4) {
            LU->focus_index += 1; wait_for_release(sfKeyRight); return;
        }
    }
}

// function to wait for the release of a key before continuing
void wait_for_release(int key)
{
    while (KEYPRESSED(key));
}
