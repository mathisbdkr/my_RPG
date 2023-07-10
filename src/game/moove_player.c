/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** moove_player
*/

#include "game.h"
#include "game_struct.h"

static sfVector2f change_coord_pt2(sfVector2f pos,
    sfVector2u size, sfVector2u screen, struct game_t *game)
{
    sfVector2f play_pos = sfSprite_getPosition(game->player_sprite);
    sfVector2f center = get_position(screen.x / 2, screen.y / 2);
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue && pos.x <= screen.x / 2
    && play_pos.x <= center.x) {
        game->direction = 3;
        check_collision(game, sfKeyQ);
        pos.x += game->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue && pos.x +
        (size.x * 2) >= screen.x / 2 && play_pos.x >= center.x) {
        game->direction = 2;
        check_collision(game, sfKeyD);
        pos.x -= game->speed;
    }
    return pos;
}

sfVector2f change_coord(sfVector2f pos,
    sfVector2u size, sfVector2u screen, struct game_t *game)
{
    game->speed = 4;
    sfVector2f play_pos = sfSprite_getPosition(game->player_sprite);
    sfVector2f center = get_position(screen.x / 2, screen.y / 2);
    if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue && game->speed != 0)
        game->speed = 6;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && pos.y <= screen.y / 2 &&
    play_pos.y <= center.y) {
        game->direction = 1;
        check_collision(game, sfKeyZ);
        pos.y += game->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        game->direction = 0;
        check_collision(game, sfKeyS);
        pos.y -= game->speed;
    }
    pos = change_coord_pt2(pos, size, screen, game);
    game->speed = 4;
    return pos;
}
