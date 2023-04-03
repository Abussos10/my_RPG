/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main.c
*/

#include "../include/rpg.h"

int main(int ac, char **av)
{
    global_t *ALL = malloc(sizeof(global_t));
    usage(ac, av, ALL);
    if (!(ALL->settings.window)) return 84;
    screenopen(ALL);
    free(ALL);
    return (0);
}