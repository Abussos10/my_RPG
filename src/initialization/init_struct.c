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
    all->game_menu_state = 0;
    all->settings_menu_state = 0;
    LUI->sword_status = 0;
}