/*
** EPITECH PROJECT, 2023
** merge
** File description:
** exit_button
*/

#include "my.h"

static void text_exit(struct win_t *win, sfVector2f pos)
{
    sfVector2f size = get_position(1,1);
    sfText *text = made_txt("reset", pos, size, win->font);
    sfRenderWindow_drawText(win->window, text, 0);
    pos.x += 135;
    text = made_txt("save", pos, size, win->font);
    sfRenderWindow_drawText(win->window, text, 0);
}

static void hit(struct win_t *win, sfRectangleShape *rect, int i)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    if (sfFloatRect_contains(&bound,win->mouse_pos.x, win->mouse_pos.y) &&
    sfMouse_isButtonPressed(0)) {
        if (i == 0) {
            win->type_close = 0;
        }
        if (i == 1) {
            win->type_close = 1;
        }
        win->open = 0;
    }
}

void settings_exit(struct win_t *win)
{
    sfVector2f pos = get_position(200, 620);
    sfVector2f size = get_position(110, 40);
    sfColor color = sfColor_fromRGBA(100, 100, 100, 200);
    sfRectangleShape *rect;
    pos.x -= 5;
    for (int i = 0; i < 2; i++) {
        rect = made_button(size, pos, color);
        hit(win, rect, i);
        pos.x += 130;
        sfRenderWindow_drawRectangleShape(win->window, rect, 0);
    }
    pos = get_position(200, 620);
    text_exit(win, pos);
}
