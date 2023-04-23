/*
** EPITECH PROJECT, 2023
** initialize my struct
** File description:
** init_struct
*/

#include "../../include/rpg.h"

// function that initialize my main structure
void initialize_all(global_t *all)
{
    all->settings.view = sfView_create();
    all->enemy->life = 100;
    all->game_menu_state = 0;
    all->settings_menu_state = 0;
    LUI->index_hpot = 1; LUI->index_sword = 5; LUI->sword_status = 0;
    LUI->hpot_status = 0; LUI->focus_index = 0; LUH->health_status = 2;
    LUI->hpot_picked = 0;
    all->dead_g = 0;
    all->dead_n = 0;
}
