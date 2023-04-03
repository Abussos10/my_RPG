/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_strcmp.c
*/

#include "../include/rpg.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}
