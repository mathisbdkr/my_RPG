/*
** EPITECH PROJECT, 2023
** merge
** File description:
** credit
*/

#include "my.h"
#include "menu_struct.h"

static int close_win(struct win_t *win, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        }
        return 1;
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(win->window);
        return 1;
    }
    return 0;
}

static void loop(struct win_t *win, sfVector2u size_win, sfText **txt,
    sfSprite *back)
{
    int close = 0;
    sfEvent event;
    for (float i = size_win.y; i > -2070 && close != 1; i--) {
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawSprite(win->window, back, 0);
        sfRenderWindow_pollEvent(win->window, &event);
        close = close_win(win, event);
        for (int k = 0; k < win->nb_ligne_credit; k++) {
            sfVector2f size = sfText_getScale(txt[k]);
            sfVector2f posi = sfText_getPosition(txt[k]);
            sfText_setScale(txt[k], get_position(size.x - 0.00099,
            size.y - 0.001));
            sfText_setPosition(txt[k], get_position(posi.x, posi.y - 1));
            sfRenderWindow_drawText(win->window, txt[k], 0);
        }
        sfRenderWindow_display(win->window);
    }
}

void credit(struct win_t *win)
{
    sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
    sfSprite *back = background_sprite("src/assets/credit.png", win->window);
    sfVector2u size_win = sfRenderWindow_getSize(win->window);
    sfText **txt = open_credit(win,get_position(1.5,1.8), size_win, win->font);
    sfMusic *music = sfMusic_createFromFile("src/song/credit.ogg");
    sfMusic_play(music);
    sfMusic_setVolume(music, win->volume_music);
    sfRenderWindow_setFramerateLimit(win->window, 75);

    loop(win, size_win, txt, back);
    sfMusic_destroy(music);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
}
