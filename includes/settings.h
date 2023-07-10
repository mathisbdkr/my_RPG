/*
** EPITECH PROJECT, 2023
** test
** File description:
** struc
*/

#ifndef STRUC_H_
    #define STRUC_H_
    #include "my.h"

struct win_t {
    int open;
    int type_close;
    sfRenderWindow *window;
    sfVector2f mouse_pos;
    sfSprite *params_back;
    sfFont *font;
    sfEvent event;
    sfMusic *music;
    sfSprite *mouse;
    int nb_ligne_credit;
    int fps_select;
    int size_select;
    int vsync;
    int volume_general;
    int volume_music;
    int volume_effect;
    int is_fullscreen;
};


#endif /* !STRUC_H_ */
