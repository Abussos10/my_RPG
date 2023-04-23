/*
** EPITECH PROJECT, 2023
** my_rpgg
** File description:
** caca
*/

#include "../../include/rpg.h"

void update_enemy(global_t *all)
{
    if (all->enemy->life == 0)
        all->dead_g = 1;
    if (all->enemy->life_d == 0)
        all->dead_n = 1;
}
