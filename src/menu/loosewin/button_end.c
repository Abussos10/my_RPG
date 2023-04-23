/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button
*/

#include "../../../include/rpg.h"

int button_handl(global_t *glob)
{
    glob->settings.m_p = sfMouse_getPositionRenderWindow(glob->settings.window);
    if (glob->settings.m_p.x >= 473 &&
        glob->settings.m_p.x <= 630 &&
        glob->settings.m_p.y >= 233 &&
        glob->settings.m_p.y <= 301) {
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
                sfRenderWindow_close(glob->settings.window);
    }
    return (0);
}
