/*
** EPITECH PROJECT, 2023
** handle the end menu pos
** File description:
** end_menu
*/

#include "../../include/rpg.h"

// function that handle the position of the end menu (offset player)
void end_menu_handler(global_t *all)
{
    sfVector2f player_pos = GET_POS(all->player->sprt);
    sfVector2f offset;
    offset.x = player_pos.x - 959; offset.y = player_pos.y - 540;
    SETPOS(all->end->l_sp, offset);
    SETPOS(all->end->w_sp, offset);
}
