/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** *
*/

//#include "../../include/rpg.h"
//
//void unmoved_animation(object_t *player)
//{
//    int widthmax = 32 * 13;
//
//    player->rect.top = 0;
//    player->anim_clock->time = sfClock_getElapsedTime   player->anim_clock->clk);
//    if (sfTime_asMilliseconds   player->anim_clock->time) >= 100) {
//        sfClock_restart player->anim_clock->clk);
//        player->rect.left += 32;
//        if (player->rect.left >= widthmax)
//            player->rect.left = 0;
//        sfSprite_setTextureRect (player->sprt, player->rect);
//    }
//}
//
//void right_animation(object_t *player)
//{
//    int widthmax = 32 * 8;
//
//    player->rect.top = 32;
//    anim_clock->time = sfClock_getElapsedTime   player->anim_clock->clk);
//    if (sfTime_asMilliseconds   player->anim_clock->time) >= 100) {
//        sfClock_restart player->anim_clock->clk);
//        player->player->rect.left += 32;
//        if  player->player->rect.left >= widthmax)
//            player->player->rect.left = 0;
//        sfSprite_setTextureRect player->player->sprt,    player->player->rect);
//    }
//}
//
//void left_animation(object_t *player)
//{
//    int widthmax = 32 * 8;
//
//    player->player->rect.top = 288;
//    player->anim_clock->time = sfClock_getElapsedTime   player->anim_clock->clk);
//    if (sfTime_asMilliseconds   player->anim_clock->time) >= 100) {
//        sfClock_restart player->anim_clock->clk);
//        player->player->rect.left += 32;
//        if  player->player->rect.left >= widthmax)
//            player->player->rect.left = 0;
//        sfSprite_setTextureRect player->player->sprt,    player->player->rect);
//    }
//}