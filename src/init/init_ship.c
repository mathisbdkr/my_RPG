/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_ship
*/

#include "menu_struct.h"
#include "my.h"

static sfSprite *set_sprite(char *path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile
    (path, NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setScale(sprite, get_position(0.7, 0.7));
    return sprite;
}

static float *malloc_line(float *ligne, int i, int y)
{
    if (i < 5) {
        srand(rand());
        ligne[0] = 0;
        ligne[1] = -100 - (i * 200);
        ligne[2] = rand() % y;
    }
    if (i >= 5) {
        srand(rand());
        ligne[0] = 1;
        ligne[1] = 600 + (i * 200);
        ligne[2] = rand() % y;
    }
    return ligne;
}

static void set_ship(struct backship_t *ship)
{
    ship->ship[0] = malloc(sizeof(sfSprite *));
    ship->ship[0] = set_sprite("./src/assets/menu_ship/st3.png");
    ship->ship[1] = malloc(sizeof(sfSprite *));
    ship->ship[1] = set_sprite("./src/assets/menu_ship/AA-9.png");
    ship->ship[2] = malloc(sizeof(sfSprite *));
    ship->ship[2] = set_sprite("./src/assets/menu_ship/speeder.png");
    ship->ship[3] = malloc(sizeof(sfSprite *));
    ship->ship[3] = set_sprite("./src/assets/menu_ship/taxi.png");
    ship->ship[4] = malloc(sizeof(sfSprite *));
    ship->ship[4] = set_sprite("./src/assets/menu_ship/jedi.png");
}

void init_ship(struct backship_t *ship, menu_t *menu)
{
    ship->window = menu->menu_window;
    ship->ship_one = set_sprite("./src/assets/menu_ship/st3.png");
    ship->ship_pos = malloc(sizeof(float *) * 10);
    ship->ship = malloc(sizeof(float *) * 5);
    sfVector2u size = sfRenderWindow_getSize(ship->window);
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        srand(rand());
        ship->ship_pos[i] = malloc(sizeof(float) * 3);
        ship->ship_pos[i] = malloc_line(ship->ship_pos[i], i, rand() % size.y);
    }
    set_ship(ship);
}
