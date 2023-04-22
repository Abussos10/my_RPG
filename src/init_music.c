/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_music
*/

#include "../include/rpg.h"

void init_music_game(music_t *music)
{
    music->music = sfMusic_createFromFile("assets/main.ogg");
}