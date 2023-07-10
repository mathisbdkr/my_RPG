/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** menu_struct
*/

#ifndef MENU_STRUCT_H_
    #define MENU_STRUCT_H_

    #define NB_BUTTON 5
    #define NB_FONTS 3

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

// STRUCT //

typedef struct s_menu menu_t;
typedef struct s_button button_t;

struct s_button {
    sfRectangleShape *rect;
    sfText *text;
    sfVector2f pos;
    sfVector2f size;
};

struct s_menu {
    button_t **button;
    sfSprite *background;
    sfTexture *texture_background;
    sfRenderWindow *menu_window;
    sfVector2f mouse_pos;
    sfMusic *music;
};

struct backship_t {
    sfRenderWindow *window;
    float **ship_pos;
    sfSprite **ship;
    sfSprite *ship_one;
};

enum {
    PLAY,
    LOAD_GAME,
    SETTINGS,
    CREDITS,
    EXIT,
};

static char *const fonts_path[NB_FONTS] = {
    "src/fonts/army.ttf",
    "src/fonts/calibril.ttf",
    "src/fonts/Starjhol2.ttf"
};

static char *const text_button[NB_BUTTON] = {
    "play",
    "load game",
    "settings",
    "credits",
    "exit"
};

static sfVector2f const position_button[NB_BUTTON] = {
    {540.0, 300.0},
    {540.0, 350.0},
    {540.0, 400.0},
    {540.0, 450.0},
    {540.0, 500.0}
};


// INIT FUNCTION //

menu_t *init_menu(void);
sfRectangleShape *init_rectangle(sfVector2f pos, sfVector2f size,
    sfColor color_in, sfColor color_out);
sfText *init_text(char *text, int kind, sfVector2f pos, int size);

// DISPLAY FUNCION //

int display_menu(menu_t *menu);


#endif /* !MENU_STRUCT_H_ */
