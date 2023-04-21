#include <SFML/Graphics.h>
#include "../../include/rpg.h"

void deplacer_sprite(sfSprite* sprite, float vitesse) {
    float x = sfSprite_getPosition(sprite).x;
    float y = sfSprite_getPosition(sprite).y;

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        x -= vitesse;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        x += vitesse;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        y -= vitesse;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        y += vitesse;
    }

    sfSprite_setPosition(sprite, (sfVector2f) { x, y });
}
