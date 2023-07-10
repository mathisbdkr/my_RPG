/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_stormtrops
*/

#include "game.h"
#include "game_struct.h"

void init_strom_troops(struct game_t *game)
{
    game->pos_storm.x = 0;
    game->pos_storm.y = 0;
    game->storm = sfSprite_create();
    game->storm_texture = sfTexture_createFromFile(
        "src/assets/sprite/ennemies.png",NULL);
    sfSprite_setTexture(game->storm, game->storm_texture, sfFalse);
    sfSprite_setScale(game->storm, get_position(2, 2));
}
