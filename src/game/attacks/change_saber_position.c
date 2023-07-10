/*
** EPITECH PROJECT, 2023
** change saber position
** File description:
** changer saber position
*/

#include "game.h"
#include "game_struct.h"

void change_weapon_position_right(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfSprite_setRotation(game->attacks.weapon_sprite, -90);
    game->attacks.weapon_pos = (sfVector2f) {(size_win.x / 2) + 70,
    (size_win.y / 2) + 50};
    sfSprite_setPosition(game->attacks.weapon_sprite,
    game->attacks.weapon_pos);
    sfSprite_setRotation(game->attacks.weapon_sprite, 90);
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void change_weapon_position_left(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfSprite_setRotation(game->attacks.weapon_sprite, 90);
    game->attacks.weapon_pos = (sfVector2f) {(size_win.x / 2) - 5,
    (size_win.y / 2) + 50};
    sfSprite_setPosition(game->attacks.weapon_sprite,
    game->attacks.weapon_pos);
    sfSprite_setRotation(game->attacks.weapon_sprite, 270);
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void change_weapon_position_up(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    game->attacks.weapon_pos = (sfVector2f) {(size_win.x / 2) + 55,
    (size_win.y / 2) + 15};
    sfSprite_setPosition(game->attacks.weapon_sprite,
    game->attacks.weapon_pos);
    sfSprite_setRotation(game->attacks.weapon_sprite, 0);
    sfRenderWindow_drawSprite(game->window, game->attacks.weapon_sprite, 0);
}

void change_weapon_position_down(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfSprite_setRotation(game->attacks.weapon_sprite, 180);
    game->attacks.weapon_pos = (sfVector2f) {(size_win.x / 2) + 15,
    (size_win.y / 2) + 80};
    sfSprite_setPosition(game->attacks.weapon_sprite, game->attacks.weapon_pos);
    sfSprite_setRotation(game->attacks.weapon_sprite, 180);
}
