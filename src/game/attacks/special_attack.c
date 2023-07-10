/*
** EPITECH PROJECT, 2023
** special attack
** File description:
** special attack
*/

#include "game.h"
#include "game_struct.h"

static void special_position_2(struct game_t *game, sfVector2u size_win)
{
    if (game->attacks.direction == 2) {
        game->attacks.weapon_pos =
        (sfVector2f) {size_win.x / 2 - 5, size_win.y / 2 + 50};
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    if (game->attacks.direction == 3) {
        game->attacks.weapon_pos =
        (sfVector2f) {size_win.x / 2 + 70, size_win.y / 2 + 50};
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
}

static void special_position(struct game_t *game, sfVector2u size_win)
{
    if (game->attacks.direction == 0) {
        game->attacks.weapon_pos =
        (sfVector2f) {size_win.x / 2 + 15, size_win.y / 2 + 80};
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    if (game->attacks.direction == 1) {
        game->attacks.weapon_pos =
        (sfVector2f) {size_win.x / 2 + 55, size_win.y / 2 + 15};
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    special_position_2(game, size_win);
}

static void special_down(struct game_t *game, sfVector2u size_win)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(
        game->attacks.clock)) > 10 && game->attacks.anim == 3) {
        game->attacks.rotate += 20;
        sfSprite_setRotation(game->attacks.weapon_sprite,
        game->attacks.rotate);
        if (game->attacks.rotate >= 720) {
            game->attacks.rotate = 180;
            game->attacks.round_count++;
        }
        if (game->attacks.round_count >= 4) {
            game->attacks.anim = 0;
            game->attacks.rotate = 180;
            game->attacks.round_count = 0;
        }
        sfClock_restart(game->attacks.clock);
    }
    if (game->attacks.round_count == 0 && game->attacks.anim == 0)
        sfSprite_setRotation(game->attacks.weapon_sprite, 180);
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void special_attack(struct game_t *game, sfVector2u size_win)
{
    if (sfKeyboard_isKeyPressed(sfKeyF))
        game->attacks.anim = 3;
    if (game->attacks.anim == 3) {
        special_position(game, size_win);
        special_down(game, size_win);
    }
}
