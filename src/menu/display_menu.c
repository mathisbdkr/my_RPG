/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** display_menu
*/

#include "menu_struct.h"
#include "my.h"

static void display_button(menu_t *menu, struct win_t *win)
{
    for (int i = 0; i < NB_BUTTON; i++) {
        sfRenderWindow_drawRectangleShape(menu->menu_window,
            menu->button[i]->rect, NULL);
        sfRenderWindow_drawText(menu->menu_window,
            menu->button[i]->text, NULL);
        button_redirection(menu, win, i);
    }
}

static void analyse_menu_event(menu_t *menu)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(menu->menu_window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(menu->menu_window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
            sfRenderWindow_close(menu->menu_window);
        }
    }
}

static void size_background(menu_t *menu)
{
    sfVector2u size_win = sfRenderWindow_getSize(menu->menu_window);
    sfFloatRect sprite_rect = sfSprite_getLocalBounds(menu->background);

    float scale_x = size_win.x / sprite_rect.width;
    float scale_y = size_win.y / sprite_rect.height;

    sfSprite_setScale(menu->background, (sfVector2f){scale_x, scale_y});
}

static void loop_menu(menu_t *menu, struct win_t *win, struct backship_t *ship)
{
    while (sfRenderWindow_isOpen(menu->menu_window)) {
        size_background(menu);
        menu->mouse_pos = mouse_position(menu->menu_window);
        win->mouse_pos = menu->mouse_pos;
        sfSprite_setPosition(win->mouse, win->mouse_pos);
        sfRenderWindow_drawSprite(win->window, win->mouse, 0);
        analyse_menu_event(menu);
        sfRenderWindow_display(menu->menu_window);
        sfRenderWindow_clear(menu->menu_window, sfBlack);
        sfRenderWindow_drawSprite(menu->menu_window, menu->background, NULL);
        back_ship(ship);
        display_button(menu, win);
    }
}

int display_menu(menu_t *menu)
{
    struct win_t *win = malloc(sizeof(struct win_t));
    struct backship_t *ship = malloc(sizeof(struct backship_t));
    win->window = menu->menu_window;
    init_window(win);
    init_ship(ship, menu);
    sfMusic *music = sfMusic_createFromFile("src/song/main_menu.ogg");
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    menu->music = music;
    win->music = music;
    loop_menu(menu, win, ship);
    return 0;
}
