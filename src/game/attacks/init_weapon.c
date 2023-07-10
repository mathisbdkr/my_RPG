/*
** EPITECH PROJECT, 2023
** init saber
** File description:
** init saber
*/

#include "game.h"
#include "game_struct.h"

void init_attack(struct game_t *game)
{
    game->attacks.weapon_texture =
    sfTexture_createFromFile("./src/assets/item/young_slayer_2000.png", 0);
    game->attacks.weapon_sprite = sfSprite_create();
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    game->attacks.weapon_pos =
    (sfVector2f) {size_win.x / 2 + 15, size_win.y / 2 + 80};
    game->attacks.weapon_scl = (sfVector2f) {0.6, 0.6};
    sfSprite_setTexture(game->attacks.weapon_sprite,
    game->attacks.weapon_texture, 0);
    sfSprite_setPosition(game->attacks.weapon_sprite, game->attacks.weapon_pos);
    sfSprite_setScale(game->attacks.weapon_sprite, game->attacks.weapon_scl);
    sfSprite_setRotation(game->attacks.weapon_sprite, 180);
    sfSprite_setOrigin(game->attacks.weapon_sprite, game->attacks.weapon_pos);
    game->attacks.mode = 0;
    game->attacks.anim = 0;
    game->attacks.round_count = 0;
    game->attacks.direction = 0;
    game->attacks.rotate = 180;
    game->attacks.clock = sfClock_create();
}
