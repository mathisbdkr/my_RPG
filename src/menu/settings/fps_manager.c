/*
** EPITECH PROJECT, 2023
** test
** File description:
** fps_manager
*/

#include "my.h"

void change_fps(struct win_t *win)
{
    if (win->fps_select == 0)
        sfRenderWindow_setFramerateLimit(win->window, 45);
    if (win->fps_select == 1)
        sfRenderWindow_setFramerateLimit(win->window, 60);
    if (win->fps_select == 2)
        sfRenderWindow_setFramerateLimit(win->window, 90);
}

sfRectangleShape *button_pressed(sfVector2f size, sfVector2f pos,
    struct win_t *win, int i)
{
    sfRectangleShape *button;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 100);
    button = made_button(size, pos, color);
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button);

    if ((sfFloatRect_contains(&bound,win->mouse_pos.x, win->mouse_pos.y) &&
    sfMouse_isButtonPressed(0)) || i == win->fps_select) {
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
        win->fps_select = i;
        change_fps(win);
        return button;
    }
    if (i == win->fps_select)
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
    if (sfFloatRect_contains(&bound,win->mouse_pos.x, win->mouse_pos.y)) {
        color.a += 100;
        sfRectangleShape_setFillColor(button, color);
    }
    return button;
}

void text_fps(struct win_t *win, sfVector2f pos)
{
    sfFont *font = win->font;
    sfVector2f size = get_position(1, 1);
    sfRenderWindow_drawText(win->window, made_txt("45", pos, size, font), 0);
    pos.x += 125;
    sfRenderWindow_drawText(win->window, made_txt("60", pos, size, font), 0);
    pos.x += 125;
    sfRenderWindow_drawText(win->window, made_txt("90", pos, size, font), 0);
}

void set_button(sfVector2f size, sfVector2f pos, struct win_t *win)
{
    sfRectangleShape *button;
    size = get_position(100, 50);
    pos = get_position(pos.x - 90, pos.y + 60);

    for (int i = 0; i < 3; i++) {
        button = button_pressed(size, pos, win, i);
        sfRenderWindow_drawRectangleShape(win->window, button, NULL);
        sfRectangleShape_destroy(button);
        pos.x += 125;
    }
    pos.y += 5;
    pos.x -= 348;
    text_fps(win, pos);
}

void fps_manager(struct win_t *win)
{
    sfVector2f pos = get_position(900, 200);
    sfVector2f size = get_position(1, 1);
    sfFont *font = win->font;
    sfRenderWindow_drawText(win->window, made_txt("    fps", pos, size, font)
    , NULL);
    set_button(size, pos, win);
}
