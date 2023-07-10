/*
** EPITECH PROJECT, 2023
** test
** File description:
** song_manager
*/

#include "my.h"

void song_manager(struct win_t *win)
{
    sfVector2f pos = get_position(300, 100);
    sfVector2f size = get_position(1.5, 1.5);
    sfFont *font = win->font;
    sfRenderWindow_drawText(win->window, made_txt("song",
    pos, size, font), NULL);
    pos = get_position(50, 200);
    size = get_position(1, 1);
    sfRenderWindow_drawText(win->window, made_txt("general:",
    pos, size, font), NULL);
    pos.y += 100;
    sfRenderWindow_drawText(win->window, made_txt("music:",
    pos, size, font), NULL);
    pos.y += 100;
    sfRenderWindow_drawText(win->window, made_txt("effect:",
    pos, size, font), NULL);
    for (int i = 0; i < 2; i++) {
        volume_bare(win);
    }
}
