/*
** EPITECH PROJECT, 2023
** test
** File description:
** settings_menu.c
*/

#include "my.h"

void settings_menu(struct win_t *win)
{
    sfRenderWindow_drawSprite(win->window, win->params_back, NULL);
    sfVector2f pos = get_position(550, 0);
    sfVector2f size = get_position(1.5, 1.5);
    sfFont *font = win->font;
    sfRenderWindow_drawText(win->window, made_txt("Settings",
    pos, size, font), NULL);
    song_manager(win);
    win_manager(win);
}
