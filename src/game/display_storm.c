/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** display_storm
*/

#include "game_struct.h"
#include "game.h"

void display_storm(struct game_t *game)
{
    sfVector2f pos_map = sfSprite_getPosition(game->map);
    sfSprite_setPosition(game->storm,
    get_position(pos_map.x + 1100, pos_map.y + 650));
    sfRenderWindow_drawSprite(game->window, game->storm, NULL);
}
