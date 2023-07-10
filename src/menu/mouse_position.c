/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** mouse_position
*/

#include "menu_struct.h"
#include "my.h"

sfVector2f mouse_position(sfRenderWindow *window)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow
    (window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords
    (window,pos_mouse, NULL);
    return mouse_pos;
}
