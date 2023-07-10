/*
** EPITECH PROJECT, 2023
** test
** File description:
** curseur_bare
*/

#include "my.h"

static void change_volume(struct win_t *win, sfVector2f pos, int i)
{
    sfVector2f mouse = win->mouse_pos;

    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x &&
    mouse.y <= pos.y + 35 && mouse.y >= pos.y - 10 &&
    sfMouse_isButtonPressed(0) && i == 0) {
        win->volume_general = (mouse.x - pos.x) / 2;
    }

    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x &&
    mouse.y <= pos.y + 35 && mouse.y >= pos.y - 10 &&
    sfMouse_isButtonPressed(0) && i == 1) {
        win->volume_music = (mouse.x - pos.x) / 2;
    }

    if (mouse.x <= pos.x + 200 && mouse.x >= pos.x &&
    mouse.y <= pos.y + 35 && mouse.y >= pos.y - 10 &&
    sfMouse_isButtonPressed(0) && i == 2) {
        win->volume_effect = (mouse.x - pos.x) / 2;
    }
}

static sfVector2f pos_curseur(struct win_t *win, sfVector2f pos, int i)
{
    if (i == 0) {
        pos.x += win->volume_general * 2;
    }
    if (i == 1) {
        pos.x += win->volume_music * 2;
    }
    if (i == 2) {
        pos.x += win->volume_effect * 2;
    }
    return pos;
}

static void aligne_volume(struct win_t *win)
{
    if (win->volume_general < win->volume_music)
        win->volume_music = win->volume_general;
    if (win->volume_general < win->volume_effect)
        win->volume_effect = win->volume_general;
}

void curseur_bare(struct win_t *win, sfVector2f pos, int i)
{
    pos.y += 9;
    sfVector2f size = get_position(4, 20);
    sfColor color = sfColor_fromRGB(255, 195, 30);
    change_volume(win, pos, i);
    aligne_volume(win);
    pos = pos_curseur(win, pos, i);
    sfRectangleShape *bare = made_button(size, pos, color);
    sfRenderWindow_drawRectangleShape(win->window, bare, 0);
    sfRectangleShape_destroy(bare);
}
