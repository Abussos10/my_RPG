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

int my_strcmp(char *base, char *acomp)
{
    int i = 0;
    int baselen = my_strlen(base);
    int acomplen = my_strlen(acomp);

    if (acomplen != baselen) return (1);
    for (; base[i]; ++i) { if (base[i] != acomp[i]) return (1); } return (0);
}