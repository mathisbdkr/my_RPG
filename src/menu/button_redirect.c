/*
** EPITECH PROJECT, 2023
** test
** File description:
** button_redirect
*/

#include "menu_struct.h"
#include "game.h"
#include "my.h"

static void redirect_pt2(menu_t *menu, struct win_t *win, int i)
{
    sfRectangleShape *rect = menu->button[i]->rect;
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = menu->mouse_pos;

    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == PLAY) {
        game_luncher(win, sfFalse);
    }
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == 3) {
        sfMusic_pause(menu->music);
        credit(win);
        sfMusic_play(menu->music);
    }
}

void button_redirection(menu_t *menu, struct win_t *win, int i)
{
    sfRectangleShape *rect = menu->button[i]->rect;
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = menu->mouse_pos;
    sfMusic_setVolume(menu->music, win->volume_music);
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == LOAD_GAME) {
        game_luncher(win, sfTrue);
    }
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == SETTINGS) {
        menu_settings(win);
        win->open = 1;
    }
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == EXIT) {
        sfRenderWindow_close(menu->menu_window);
    }
    redirect_pt2(menu, win, i);
}
