/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** button_events
*/

#include "menu_struct.h"

sfBool is_clicked(sfRenderWindow *window, sfRectangleShape *rectangle)
{
    sfVector2f pos = sfRectangleShape_getPosition(rectangle);
    sfVector2f size = sfRectangleShape_getSize(rectangle);
    sfVector2i wpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, wpos, NULL);

    if ((pos.x <= mouse.x && pos.x + size.x >= mouse.x)
        && (pos.y <= mouse.y && pos.y + size.y >= mouse.y)) {
            return sfTrue;
        }
    return sfFalse;
}

static void check_button_status(menu_t *menu)
{
    for (int i = 0; i < NB_BUTTON; i++) {
        if (is_clicked(menu->menu_window, menu->button[i]->rect)) {
            menu->button[i]->hover = sfTrue;
        } else {
            menu->button[i]->hover = sfFalse;
        }
        if (is_clicked(menu->menu_window, menu->button[i]->rect)
            && sfMouse_isButtonPressed(0)) {
                menu->button[i]->enabled = sfTrue;
        } else {
            menu->button[i]->enabled = sfFalse;
        }
    }
}

void check_button(menu_t *menu)
{
    check_button_status(menu);

    for (int i = 0; i < NB_BUTTON; i++) {
        if (menu->button[i]->enabled) {
            sfRectangleShape_setFillColor(menu->button[i]->rect, sfYellow);
        } else {
            sfRectangleShape_setFillColor(menu->button[i]->rect, sfTransparent);
        }
        if (menu->button[i]->hover) {
            sfRectangleShape_setFillColor(menu->button[i]->rect, sfBlack);
        } else {
            sfRectangleShape_setFillColor(menu->button[i]->rect, sfTransparent);
        }
    }
}
