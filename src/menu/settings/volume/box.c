/*
** EPITECH PROJECT, 2023
** test
** File description:
** box
*/

#include "my.h"

static void bord_box(struct win_t *win, sfVector2f pos, sfVector2f size)
{
    sfCircleShape *cercle = sfCircleShape_create();
    sfCircleShape_setRadius(cercle, size.y / 2);
    sfCircleShape_setFillColor(cercle, sfBlack);
    sfCircleShape_setOutlineThickness(cercle, 1);
    sfCircleShape_setOutlineColor(cercle, sfColor_fromRGB(255, 195, 30));
    sfCircleShape_setPosition(cercle, get_position(pos.x - size.y / 2, pos.y));
    sfRenderWindow_drawCircleShape(win->window, cercle, 0);
}

static void clear_line(struct win_t *win, sfVector2f pos, sfVector2f size)
{
    size.y -= 2;
    pos.y += 1;
    sfRectangleShape *button = sfRectangleShape_create();
    sfRectangleShape_setSize(button, size);
    sfRectangleShape_setPosition(button, pos);
    sfRectangleShape_setFillColor(button, sfBlack);
    sfRectangleShape_setOutlineThickness(button, 1);
    sfRectangleShape_setOutlineColor(button, sfColor_fromRGB(0, 0, 0));
    sfRenderWindow_drawRectangleShape(win->window, button, 0);
}

void create_box(struct win_t *win, sfVector2f pos)
{
    sfVector2f size = get_position(200, 40);
    sfColor color = sfColor_fromRGBA(0,0,0,0);
    sfRectangleShape *box = made_button(size, pos, color);
    sfRenderWindow_drawRectangleShape(win->window, box, 0);
    bord_box(win, pos, size);
    pos.x += size.x;
    bord_box(win, pos, size);
    pos.x -= size.x;
    clear_line(win, pos, size);
}
