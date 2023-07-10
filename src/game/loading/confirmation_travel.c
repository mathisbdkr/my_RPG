/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** confirmation_travel
*/

#include "game.h"
#include "game_struct.h"

int confirm(struct game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        make_game_map(game, game->new_map - 1);
        chargement(game);
        game->new_map = 0;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        game->new_map = 0;
        sfVector2f map_pos = sfSprite_getPosition(game->map);
        map_pos.y -= 100;
        sfSprite_setPosition(game->map, map_pos);
        while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue);
        return 0;
    }
    return 1;
}
