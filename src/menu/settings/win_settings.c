/*
** EPITECH PROJECT, 2023
** test
** File description:
** song_manager
*/

#include "my.h"

void win_manager(struct win_t *win)
{
    sfVector2f pos = get_position(900, 100);
    sfVector2f size = get_position(1.5, 1.5);
    sfFont *font = win->font;
    sfRenderWindow_drawText(win->window, made_txt("window", pos, size,
    font), NULL);
    fps_manager(win);
    pos.y += 250;
    pos.x -= 50;
    sfRenderWindow_drawText(win->window, made_txt("window size",
    pos, size, font), NULL);
    size_win_manager(win);
    pos.y += 200;
    pos.x += 50;
    sfRenderWindow_drawText(win->window, made_txt("vsync",
    pos, size, font), NULL);
    vsync_manager(win);
}
