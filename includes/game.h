/*
** EPITECH PROJECT, 2023
** test
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "my.h"

// STRUCT //

struct game_t;


// INIT //

struct game_t *init_game(struct win_t *win);
void make_game_map(struct game_t *game, int nb);
void init_inv(struct game_t *game);
struct player_stat_t *init_player_stat(void);


// LOAD SCREEN //

int confirm(struct game_t *game);
void chargement(struct game_t *game);


// ANIM PLAYER //

void init_kaelan(struct game_t *game);
void animate_sprite(sfSprite *sprite, sfClock *clock, int *frame,
int direction);


// MOVEMENT //

sfVector2f change_coord(sfVector2f pos,
    sfVector2u size, sfVector2u screen, struct game_t *game);


// DISPLAY //

void display_objects(struct win_t *win, struct game_t *game,
    sfEvent event);


// COLLISION //

sfColor init_pnj_color(void);
sfColor wall_colision(struct game_t *game, sfImage *back_map,
    int pixel_to_check);
void check_collision(struct game_t *game, int key);


// STAT PLAYER //

void player_level(struct game_t *game);
void display_level(struct game_t *game);
void display_stat(struct game_t *game);


// CHECK COLOR //

int is_color_is(sfColor color_a, sfColor color_b);


// INTERACTION //

void handle_interaction(struct game_t *game);


// PAUSE_MENU //

void pause_game(struct win_t *win, struct game_t *game);
void pause_background(struct game_t *game, sfVector2f size_back);


// MINI MAP//

void minimap(struct game_t *game);


// INVENTAIRES //

void item_type(struct game_t *game, int i, int type);
void inventaire(struct game_t *game);
void display_back_inv(struct game_t *game);
void display_item_box(struct game_t *game, sfVector2f pos);
void inv_bare(struct game_t *game);
void item_armor(struct game_t *game, sfVector2f pos);
void shield_upgrade(struct game_t *game);
void shield_downgrade(struct game_t *game, int i);


// ENNEMY //

int is_kill_ennemies(struct game_t *game);
void init_strom_troops(struct game_t *game);
struct s_ennemies *init_ennemies(int quest);
void display_ennemies(struct game_t *game);


// ATTACKS //

void display_storm(struct game_t *game);
void attacks(struct game_t *game);
void init_attack(struct game_t *game);
void change_weapon_position_down(struct game_t *game);
void change_weapon_position_up(struct game_t *game);
void change_weapon_position_left(struct game_t *game);
void change_weapon_position_right(struct game_t *game);
void anim_weapon_down(struct game_t *game, sfVector2u size_win);
void anim_weapon_up(struct game_t *game, sfVector2u size_win);
void anim_weapon_left(struct game_t *game, sfVector2u size_win);
void anim_weapon_right(struct game_t *game, sfVector2u size_win);
void special_attack(struct game_t *game, sfVector2u size_win);


// SAVE GAME //

void save_game(struct game_t *game);
void load_game(struct game_t *game, char *filepath);
void load_inv(struct game_t *game, char *str);


// VICTORY //

void congraluation(struct game_t *game);



// LIB //

char **file_to_arr(char *const filepath);
void made_rond_rect(sfVector2f size, sfVector2f pos, sfColor color,
    sfRenderWindow *window);
char *my_strcat(char* src, char* dest);
char *my_strcpy(char* dest, char* src);

#endif /* !GAME_H_ */
