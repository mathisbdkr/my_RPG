/*
** EPITECH PROJECT, 2023
** test
** File description:
** vsync_manager
*/

#include "my.h"

static void wait_press(void)
{
    while (sfMouse_isButtonPressed(0)) {
    }
}

static void sync_press(struct win_t *win)
{
    sfVector2f pos = get_position(900, 610);
    sfVector2f size = get_position(160, 50);
    sfColor color = sfColor_fromRGBA(255, 255, 255, 100);
    sfRectangleShape *button = made_button(size, pos, color);
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button);
    if (sfFloatRect_contains(&bound,win->mouse_pos.x, win->mouse_pos.y) &&
    sfMouse_isButtonPressed(0)) {
        if (win->vsync == 0) {
            sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
            win->vsync = 1;
        } else {
            sfRenderWindow_setVerticalSyncEnabled(win->window, sfFalse);
            win->vsync = 0;
        }
        wait_press();
    }
    sfRenderWindow_drawRectangleShape(win->window, button, 0);
}

void vsync_manager(struct win_t *win)
{
    sync_press(win);
    sfVector2f pos = get_position(905, 615);
    sfVector2f size = get_position(1, 1);
    sfFont *font = win->font;
    if (win->vsync == 0) {
        sfRenderWindow_drawText(win->window, made_txt("desable",
        pos, size, font), NULL);
    } else {
        sfRenderWindow_drawText(win->window, made_txt("enable",
        pos, size, font), NULL);
    }
}
