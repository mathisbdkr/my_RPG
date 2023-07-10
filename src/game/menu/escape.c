/*
** EPITECH PROJECT, 2023
** test
** File description:
** escape
*/

#include "game_struct.h"
#include "my.h"

static void text_button_pause(int i, sfVector2f pos, struct game_t *game)
{
    sfText *txt = sfText_create();
    sfVector2f size = get_position(1, 1);
    sfFont *font = sfFont_createFromFile("src/fonts/Starjhol2.ttf");
    char *text = pause_txt[i];
    pos.x -= 230;
    pos.y -= 18;
    txt = made_txt(text, pos, size, font);
    sfRenderWindow_drawText(game->window, txt, 0);
    sfText_destroy(txt);
    sfFont_destroy(font);
}

static void click_button(struct win_t *win,
struct game_t *game, sfRectangleShape *rect, int i)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mouse_pos;
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == 0)
        game->pause = 0;
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == 1) {
        menu_settings(win);
        sfMusic_setVolume(game->music, win->volume_music);
        win->open = 1;
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    }
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == 2)
        game->end = 1;
    if (sfFloatRect_contains(&bound,pos.x, pos.y) &&
    sfMouse_isButtonPressed(0) && i == 3) {
        sfRenderWindow_close(game->window);
        game->end = 1;
    }
}

static sfRectangleShape *hover_button(struct game_t *game,
sfRectangleShape *rect)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f pos = game->mouse_pos;
    sfColor color = sfColor_fromRGBA(40, 40, 40, 220);
    if (sfFloatRect_contains(&bound,pos.x, pos.y)) {
        sfRectangleShape_setFillColor(rect, color);
    }
    return rect;
}

static void button_pause(struct win_t *win, struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f size_butt = get_position(500, 50);
    sfVector2f posi_butt = get_position(size_win.x / 2, size_win.y / 2);
    posi_butt.y -= 120;
    sfColor color = sfColor_fromRGBA(20, 20, 20, 240);
    sfRectangleShape *button = sfRectangleShape_create();
    for (int i = 0; i < 4; i++) {
        button = made_button(size_butt, posi_butt, color);
        sfRectangleShape_setOrigin(button,
        get_position(size_butt.x / 2, size_butt.y / 2));
        button = hover_button(game, button);
        sfRenderWindow_drawRectangleShape(game->window, button, 0);
        text_button_pause(i, posi_butt, game);
        click_button(win, game, button, i);
        posi_butt.y += 80;
    }
}

void pause_game(struct win_t *win, struct game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        game->pause = 0;
        while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        }
    }
    if (game->pause == 1) {
        pause_background(game, get_position(650, 380));
        button_pause(win, game);
    }
}
