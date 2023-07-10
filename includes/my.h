/*
** EPITECH PROJECT, 2023
** test
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include "include.h"
    #include "settings.h"
    #include "game.h"
    #include "menu_struct.h"

void init_ship(struct backship_t *ship, menu_t *menu);
void back_ship(struct backship_t *ship);
void button_redirection(menu_t *menu, struct win_t *win, int i);
void credit(struct win_t *win);
char **my_str_to_word_array(char *str, char sep);
sfSprite *background_sprite(char *path, sfRenderWindow *window);
sfVector2f mouse_position(sfRenderWindow *window);
int my_strlen(char const *str);
sfText **open_credit(struct win_t *win, sfVector2f
    size, sfVector2u size_win, sfFont *font);
int menu_settings(struct win_t *win);
void init_window(struct win_t *win);
void settings_menu(struct win_t *win);
sfText *made_txt(char *text, sfVector2f pos, sfVector2f size, sfFont *font);
sfVector2f get_position(float x, float y);
void song_manager(struct win_t *win);
void win_manager(struct win_t *win);
int my_getnbr(char *str);
sfRectangleShape *made_button(sfVector2f size, sfVector2f pos, sfColor color);
void fps_manager(struct win_t *win);
void size_win_manager(struct win_t *win);
void vsync_manager(struct win_t *win);
void volume_bare(struct win_t *win);
void create_box(struct win_t *win, sfVector2f pos);
void center_bare(struct win_t *win, sfVector2f pos);
void curseur_bare(struct win_t *win, sfVector2f pos, int i);
void settings_exit(struct win_t *win);
void game_luncher(struct win_t *win, sfBool is_load);
int my_put_nbr(int nb, int fd);

#endif /* !MY_H_ */
