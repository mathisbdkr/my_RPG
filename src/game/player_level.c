/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** player_level
*/

#include "game.h"
#include "game_struct.h"

void player_level(struct game_t *game)
{
    if (game->pstat->xp >= 100) {
        game->pstat->level += 1;
        game->pstat->xp -= 100;
        game->pstat->total_atk = game->pstat->level;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
        game->pstat->xp++;
}
