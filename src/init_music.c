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
    init_sound(music);
}

void init_sound(music_t *music)
{
    music->buff =
    sfSoundBuffer_createFromFile("assets/scream.ogg");
    music->sound = sfSound_create();
    sfSound_setVolume(music->sound, 60);
    sfSound_setBuffer(music->sound, music->buff);
}
