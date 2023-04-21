/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button
*/

#include "../../include/rpg.h"
#include "../../include/menu.h"

int checkbutton_play(global_t *data, button_t *button)
{
    data->settings.m_p = sfMouse_getPositionRenderWindow(data->settings.window);
    if (data->settings.m_p.x >= 348 &&
        data->settings.m_p.x <= 501 &&
        data->settings.m_p.y >= 433 &&
        data->settings.m_p.y <= 500) {
            return (1);
    }
    return (0);
}

int checkbutton_settings(global_t *data, button_t *button)
{
    data->settings.m_p = sfMouse_getPositionRenderWindow(data->settings.window);
    if (data->settings.m_p.x >= 497 &&
        data->settings.m_p.x <= 721 &&
        data->settings.m_p.y >= 577 &&
        data->settings.m_p.y <= 645) {
            sfRenderWindow_drawSprite(data->settings.window,
            button->bset_s, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
                return (1);
    }
    return (0);
}

int checkbutton_quit(global_t *data, button_t *button)
{
    data->settings.m_p = sfMouse_getPositionRenderWindow(data->settings.window);
    if (data->settings.m_p.x >= 744 &&
        data->settings.m_p.x <= 898 &&
        data->settings.m_p.y >= 717 &&
        data->settings.m_p.y <= 786) {
            sfRenderWindow_drawSprite(data->settings.window,
            button->bquit_s, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
                return (1);
    }
    return (0);
}