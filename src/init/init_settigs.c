/*
** EPITECH PROJECT, 2023
** merge
** File description:
** init_settigs
*/

#include "my.h"
#include "menu_struct.h"

static void set_back(struct win_t *win)
{
    sfSprite *background = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile
    ("src/assets/settings_back.jpg", NULL);
    sfSprite_setTexture(background, texture, 0);
    sfVector2u size_win = (sfVector2u){1920, 1029};
    sfFloatRect sprite_rect = sfSprite_getLocalBounds(background);

    float scale_x = size_win.x / sprite_rect.width;
    float scale_y = size_win.y / sprite_rect.height;

    sfSprite_setScale(background, (sfVector2f){scale_x, scale_y});
    win->params_back = background;
}

static sfSprite *set_mouse(void)
{
    sfSprite *mouse = sfSprite_create();
    sfSprite_setTexture(mouse,
    sfTexture_createFromFile("src/assets/mouse_menu.png", NULL), 0);
    sfVector2u scale = sfTexture_getSize(sfSprite_getTexture(mouse));
    sfSprite_setOrigin(mouse, get_position(scale.x / 2,scale.y / 2));
    sfSprite_setScale(mouse, get_position(0.1, 0.1));
    return mouse;
}

void init_window(struct win_t *win)
{
    win->fps_select = 0;
    win->size_select = 1;
    win->vsync = 0;
    win->volume_effect = 100;
    win->volume_general = 100;
    win->volume_music = 100;
    win->open = 1;
    win->type_close = 0;
    win->is_fullscreen = 0;
    win->font = sfFont_createFromFile("src/fonts/Starjhol2.ttf");
    win->mouse = set_mouse();
    set_back(win);
}
