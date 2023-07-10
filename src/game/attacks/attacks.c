/*
** EPITECH PROJECT, 2023
** attacks
** File description:
** attacks
*/

#include "game_struct.h"
#include "game.h"

static void change_anim_number(struct game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        game->attacks.anim = 1;
}

static void change_direction_number(struct game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        game->attacks.direction = 0;
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
        game->attacks.direction = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        game->attacks.direction = 2;
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
        game->attacks.direction = 3;
}

static void launch_weapon_anim_2(struct game_t *game, sfVector2u size_win)
{
    if (game->attacks.direction == 2 &&
        (game->attacks.anim == 0 || game->attacks.anim == 1)) {
        if (game->attacks.anim == 0)
            change_weapon_position_left(game);
        anim_weapon_left(game, size_win);
    }
    if (game->attacks.direction == 3 &&
        (game->attacks.anim == 0 || game->attacks.anim == 1)) {
        if (game->attacks.anim == 0)
            change_weapon_position_right(game);
        anim_weapon_right(game, size_win);
    }
}

static void launch_weapon_anim(struct game_t *game, sfVector2u size_win)
{
    if (game->attacks.direction == 0 &&
        (game->attacks.anim == 0 || game->attacks.anim == 1)) {
        if (game->attacks.anim == 0)
            change_weapon_position_down(game);
        anim_weapon_down(game, size_win);
    }
    if (game->attacks.direction == 1 &&
        (game->attacks.anim == 0 || game->attacks.anim == 1)) {
        if (game->attacks.anim == 0)
            change_weapon_position_up(game);
        anim_weapon_up(game, size_win);
    }
    launch_weapon_anim_2(game, size_win);
}

void attacks(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfTexture *tmp = sfTexture_createFromFile("src/assets/item/vide.png", 0);
    sfSprite_setTexture(game->attacks.weapon_sprite, tmp, 0);
    int type = game->inv[game->item_select + (NB_INV - 10)]->type;
    if (type == SWORD) {
        game->attacks.weapon_sprite = sfSprite_copy
        (game->inv[game->item_select + (NB_INV - 10)]->item);
        game->inv[game->item_select + (NB_INV - 10)]->damage +=
        game->pstat->atk_dammage;
    }
    sfSprite_setPosition(game->attacks.weapon_sprite, game->attacks.weapon_pos);
    sfSprite_setScale(game->attacks.weapon_sprite, game->attacks.weapon_scl);
    change_direction_number(game);
    launch_weapon_anim(game, size_win);
    special_attack(game, size_win);
    sfTexture_destroy(tmp);
}
