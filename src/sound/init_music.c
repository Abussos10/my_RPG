/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_music
*/

#include "../include/rpg.h"

// init the music game
void init_music_game(music_t *music, global_t *glob)
{
    music->music = sfMusic_createFromFile("assets/main.ogg");
    init_sound(music, glob->player);
}

// init the sounds
void init_sound(music_t *music, object_t *player)
{
    music->buff =
    sfSoundBuffer_createFromFile("assets/scream.ogg");
    music->sound = sfSound_create();
    sfSound_setVolume(music->sound, 60);
    sfSound_setBuffer(music->sound, music->buff);
    player->buff = sfSoundBuffer_createFromFile("sprites/pic/hurt.ogg");
    player->sound = sfSound_create();
    sfSound_setVolume(player->sound, 60);
    sfSound_setBuffer(player->sound, player->buff);
    player->scr_b = sfSoundBuffer_createFromFile("sprites/pic/scream.ogg");
    player->scr = sfSound_create();
    sfSound_setVolume(player->scr, 60);
    sfSound_setBuffer(player->scr, player->scr_b);
}
