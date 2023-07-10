/*
** EPITECH PROJECT, 2023
** merge
** File description:
** menu_settings
*/

#include "my.h"

static void close_win(struct win_t *win, sfEvent event)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->window);
    win->mouse_pos = sfRenderWindow_mapPixelToCoords
    (win->window,pos_mouse, NULL);

    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        win->open = 0;
    }
    while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
    }
    if (event.type == sfEvtClosed) {
        win->open = 0;
        sfRenderWindow_close(win->window);
    }
}

static void exit_type(struct win_t *win)
{
    if (win->type_close == 0) {
        init_window(win);
    }
}

int menu_settings(struct win_t *win)
{
    sfEvent event;
    sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
    while (win->open == 1) {
        sfVector2i pos_mouse = sfMouse_getPositionRenderWindow
        (win->window);
        win->mouse_pos = sfRenderWindow_mapPixelToCoords
        (win->window,pos_mouse, NULL);
        sfRenderWindow_pollEvent(win->window, &event);
        sfRenderWindow_clear(win->window, sfBlack);
        close_win(win, event);
        win->event = event;
        settings_menu(win);
        settings_exit(win);
        sfRenderWindow_display(win->window);
        sfMusic_setVolume(win->music, win->volume_music);
    }
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    exit_type(win);
    return 0;
}
