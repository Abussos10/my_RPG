/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** players_movements.c
*/

#include "../include/rpg.h"

int move_sprites(global_t *all)
{
    all->picture[1]->speed = 0.5;
    if (KEYPRESSED(sfKeyLeft) && KEYPRESSED(sfKeyUp)) return (1);
    if (KEYPRESSED(sfKeyLeft) && KEYPRESSED(sfKeyDown)) return (1);
    if (KEYPRESSED(sfKeyRight) && KEYPRESSED(sfKeyUp)) return (1);
    if (KEYPRESSED(sfKeyRight) && KEYPRESSED(sfKeyDown)) return (1);
    if (KEYPRESSED(sfKeyLeft)) 
        all->picture[1]->pos.x -= all->picture[1]->speed;
    if (KEYPRESSED(sfKeyUp))
        all->picture[1]->pos.y -= all->picture[1]->speed;
    if (KEYPRESSED(sfKeyRight))
        all->picture[1]->pos.x += all->picture[1]->speed;
    if (KEYPRESSED(sfKeyDown))
        all->picture[1]->pos.y += all->picture[1]->speed;
}
