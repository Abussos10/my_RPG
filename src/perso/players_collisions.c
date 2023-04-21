/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button
*/

#include "../../include/rpg.h"
#include "../../include/menu.h"

int collider(sfImage *collision, récupérer position joueur)
{
    sfColor walk_character = sfImage_getPixel(collision,(unsigned int) positionx,(unsigned int)positiony);
    sfUint32 wh = sfColor_toInteger(sfwhite);
    sfUint32 bl = sfColor_toInteger(sfBlack);
    sfUint32 wc = sfColor_toInteger(walk_character);
    if (wc != bl)
        return true;

    else 
        return false;

}
appeler la fonction ou le personnage veut aller et non sous le personnage.