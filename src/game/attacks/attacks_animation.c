/*
** EPITECH PROJECT, 2023
** attacks animations
** File description:
** attacks animations
*/

#include "game.h"
#include "game_struct.h"

void anim_weapon_right(struct game_t *game, sfVector2u size_win)
{
    sfSprite_setRotation(game->attacks.weapon_sprite, 90);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock)) > 12 &&
        game->attacks.anim == 1) {
        if (game->attacks.mode == 0)
            game->attacks.weapon_pos.x--;
        if (game->attacks.mode == 1)
            game->attacks.weapon_pos.x++;
        if (game->attacks.weapon_pos.x >= (size_win.x / 2) + 100)
            game->attacks.mode = 0;
        if (game->attacks.weapon_pos.x <= (size_win.x / 2) + 70) {
            game->attacks.mode = 1;
            game->attacks.anim = 0;
            change_weapon_position_right(game);
        }
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        game->attacks.anim = 1;
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void anim_weapon_left(struct game_t *game, sfVector2u size_win)
{
    sfSprite_setRotation(game->attacks.weapon_sprite, -90);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock)) > 12 &&
        game->attacks.anim == 1) {
        if (game->attacks.mode == 0)
            game->attacks.weapon_pos.x++;
        if (game->attacks.mode == 1)
            game->attacks.weapon_pos.x--;
        if (game->attacks.weapon_pos.x <= (size_win.x / 2) - 30)
            game->attacks.mode = 0;
        if (game->attacks.weapon_pos.x >= (size_win.x / 2)) {
            game->attacks.mode = 1;
            game->attacks.anim = 0;
            change_weapon_position_left(game);
        }
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        game->attacks.anim = 1;
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void anim_weapon_up(struct game_t *game, sfVector2u size_win)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock)) > 12 &&
        game->attacks.anim == 1) {
        if (game->attacks.mode == 0)
            game->attacks.weapon_pos.y++;
        if (game->attacks.mode == 1)
            game->attacks.weapon_pos.y--;
        if (game->attacks.weapon_pos.y <= (size_win.y / 2))
            game->attacks.mode = 0;
        if (game->attacks.weapon_pos.y >= (size_win.y / 2) + 30) {
            game->attacks.mode = 1;
            game->attacks.anim = 0;
            change_weapon_position_up(game);
        }
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        game->attacks.anim = 1;
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void anim_weapon_down(struct game_t *game, sfVector2u size_win)
{
    sfSprite_setRotation(game->attacks.weapon_sprite, 180);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock)) > 12 &&
        game->attacks.anim == 1) {
        if (game->attacks.mode == 0)
            game->attacks.weapon_pos.y++;
        if (game->attacks.mode == 1)
            game->attacks.weapon_pos.y--;
        if (game->attacks.weapon_pos.y >= (size_win.y / 2) + 100)
            game->attacks.mode = 1;
        if (game->attacks.weapon_pos.y <= (size_win.y / 2) + 70) {
            game->attacks.mode = 0;
            game->attacks.anim = 0;
            change_weapon_position_down(game);
        }
        sfSprite_setPosition(game->attacks.weapon_sprite,
        game->attacks.weapon_pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        game->attacks.anim = 1;
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}
