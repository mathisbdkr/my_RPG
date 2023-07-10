/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** display_ennemies
*/

#include "game.h"
#include "game_struct.h"

void display_ennemies(struct game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window, game->ennemies->square,
        NULL);
    sfRenderWindow_drawSprite(game->window, game->ennemies->ennemies, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->ennemies->filled_life,
        NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->ennemies->name_case,
        NULL);
    sfRenderWindow_drawText(game->window, game->ennemies->name, NULL);
}
