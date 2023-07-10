/*
** EPITECH PROJECT, 2023
** test
** File description:
** size_win_manager
*/

#include "my.h"

static void make_fullscreen(struct win_t *win)
{
    if (win->size_select == 0) {
        if (win->is_fullscreen == 0) {
            sfRenderWindow_close(win->window);
            sfRenderWindow_destroy(win->window);
            sfVideoMode mode = { 1920, 1029 , 32 };
            win->window = sfRenderWindow_create(mode, "my rpg",
            sfFullscreen, NULL);
            win->is_fullscreen = 1;
        }
    } else if (win->is_fullscreen == 1) {
        sfRenderWindow_close(win->window);
        sfRenderWindow_destroy(win->window);
        sfVideoMode mode = { 1910, 1020 , 32 };
        win->window = sfRenderWindow_create(mode, "my rpg",
        sfResize | sfClose, NULL);
        win->is_fullscreen = 0;
    }
}

void change_win_size(struct win_t *win)
{
    make_fullscreen(win);
    if (win->size_select == 1)
        sfRenderWindow_setSize(win->window, (sfVector2u){1920, 1029});
    if (win->size_select == 2)
        sfRenderWindow_setSize(win->window, (sfVector2u){1366, 716});
}

sfRectangleShape *butt_pressed(sfVector2f size, sfVector2f pos,
    struct win_t *win, int i)
{
    sfRectangleShape *button;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 100);
    button = made_button(size, pos, color);
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button);

    if ((sfFloatRect_contains(&bound,win->mouse_pos.x, win->mouse_pos.y) &&
    sfMouse_isButtonPressed(0)) || i == win->size_select) {
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
        win->size_select = i;
        change_win_size(win);
        return button;
    }
    if (i == win->size_select)
        sfRectangleShape_setFillColor(button, sfColor_fromRGBA(0,255,100,100));
    if (sfFloatRect_contains(&bound,win->mouse_pos.x, win->mouse_pos.y)) {
        color.a += 100;
        sfRectangleShape_setFillColor(button, color);
    }
    return button;
}

static void button_set(struct win_t *win, sfVector2f pos)
{
    sfRectangleShape *button;
    sfVector2f size = get_position(180, 50);
    pos.y -= 10;
    pos.x -= 10;
    for (int i = 0; i < 3; i++) {
        button = butt_pressed(size, pos, win, i);
        sfRenderWindow_drawRectangleShape(win->window, button, NULL);
        sfRectangleShape_destroy(button);
        pos.x += 200;
    }
}

void size_win_manager(struct win_t *win)
{
    sfVector2f pos = get_position(700, 450);
    sfVector2f size = get_position(0.7, 0.7);
    sfFont *font = win->font;
    button_set(win, pos);
    sfRenderWindow_drawText(win->window,
    made_txt("Full screen", pos, size, font), 0);
    pos.x += 200;
    size = get_position(0.8, 0.8);
    sfRenderWindow_drawText(win->window,
    made_txt("1920 x 1080", pos, size, font), 0);
    pos.x += 200;
    sfRenderWindow_drawText(win->window,
    made_txt("1366 x 716", pos, size, font), 0);
}
