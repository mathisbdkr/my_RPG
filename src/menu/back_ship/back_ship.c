/*
** EPITECH PROJECT, 2023
** test
** File description:
** back_ship
*/

#include "my.h"

static void move_gd(struct backship_t *ship)
{
    sfVector2u size = sfRenderWindow_getSize(ship->window);
    for (int i = 0; i < 5; i++) {
        sfSprite_setPosition(ship->ship[i],
        get_position(ship->ship_pos[i][1], ship->ship_pos[i][2]));
        if (ship->ship_pos[i][0] == 0) {
            ship->ship_pos[i][1] += 0.8;
            sfSprite_setScale(ship->ship[i], get_position(0.4, 0.4));
        }
        if (ship->ship_pos[i][1] >= size.x + 100) {
            srand(time(NULL));
            ship->ship_pos[i][1] = -100;
            ship->ship_pos[i][2] = rand() % size.y;
        }
        sfRenderWindow_drawSprite(ship->window, ship->ship[i], 0);
    }
}

static void move_dg(struct backship_t *ship)
{
    sfVector2u size = sfRenderWindow_getSize(ship->window);
    for (int i = 5; i < 10; i++) {
        sfSprite_setPosition(ship->ship[i - 5],
        get_position(ship->ship_pos[i][1], ship->ship_pos[i][2]));
        if (ship->ship_pos[i][0] == 1) {
            ship->ship_pos[i][1] -= 1;
            sfSprite_setScale(ship->ship[i - 5], get_position(-0.5, 0.5));
        }
        if (ship->ship_pos[i][1] <= -100) {
            srand(time(NULL));
            ship->ship_pos[i][1] = size.x + 100;
            ship->ship_pos[i][2] = rand() % size.y;
        }
        sfRenderWindow_drawSprite(ship->window, ship->ship[i - 5], 0);
    }
}

void back_ship(struct backship_t *ship)
{
    move_gd(ship);
    move_dg(ship);
}
