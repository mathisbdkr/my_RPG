/*
** EPITECH PROJECT, 2023
** merge
** File description:
** background_sprite
*/

#include "my.h"

sfSprite *background_sprite(char *path, sfRenderWindow *window)
{
    sfSprite *background = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(background, texture, 0);
    sfVector2u size_win = sfRenderWindow_getSize(window);
    sfFloatRect sprite_rect = sfSprite_getLocalBounds(background);

    float scale_x = size_win.x / sprite_rect.width;
    float scale_y = size_win.y / sprite_rect.height;

    sfSprite_setScale(background, (sfVector2f){scale_x, scale_y});
    return background;
}
