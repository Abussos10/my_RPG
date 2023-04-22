
void image_up(sfRenderWindow* window, sfSprite* sprite) {
    sfVector2f position = sfSprite_getPosition(sprite);
    while (position.y > sfRenderWindow_getSize(window).y -990) {
        position.y -= 1.0f;
        sfSprite_setPosition(sprite, position);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSleep(sfMilliseconds(10));
    }
}

int main()
{
    sfTexture* texture = sfTexture_createFromFile("theend.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 1080});
        image_up(window, sprite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
