/*
** EPITECH PROJECT, 2023
** sound handling
** File description:
** sound_handler
*/

#include "../../include/rpg.h"

// function that handle the sound in the game
void sound_handler(global_t *all)
{
    sfView_setSize(all->settings.view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all->settings.window, all->settings.view);
    sfMusic_play(all->music->music);
    sfMusic_setLoop(all->music->music, sfTrue);
}
