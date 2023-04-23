/*
** EPITECH PROJECT, 2023
** events handler
** File description:
** events_handler
*/

#include "../../include/rpg.h"

// function that handle any event in the game
void events_handler(global_t *all)
{
    use_item(all);
    sword_event_handler(all);
    hpot_event_handler(all);
}

// function to use an item
void use_item(global_t *all)
{
    if ((LUI->focus_index + 1) == LUI->index_hpot && LUI->hpot_status == 1) {
        if (KEYPRESSED(sfKeyE) && LUH->health_status < 3) {
            LUH->health_status += 1; wait_for_release(sfKeyE);
            LUI->hpot_status = 0;
        }
    }
}
