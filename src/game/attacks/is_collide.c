/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** is_collide
*/

#include "game.h"
#include "game_struct.h"

int is_kill_ennemies(struct game_t *game)
{
    sfImage *back_map = sfTexture_copyToImage(game->texture_back_map);

    if (is_color_is(wall_colision(game, back_map,
        (int)game->attacks.weapon_pos.x + 20), init_pnj_color())) {
    }
    return 0;
}
