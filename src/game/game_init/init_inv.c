/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_inv
*/

#include "game_struct.h"
#include "game.h"

static sfSprite *set_sprite(int nb)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile
    (item_sprite[nb], NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfVector2u size_item = sfTexture_getSize(texture);
    sfSprite_setOrigin(sprite, get_position(size_item.x / 2, size_item.y / 2));
    sfSprite_setScale(sprite, get_position(0.75, 0.75));
    return sprite;
}

void init_inv(struct game_t *game)
{
    game->inv = malloc(sizeof(struct inv_t) * (NB_INV + 1));
    for (int i = 0; i < NB_INV; i++) {
        game->inv[i] = malloc(sizeof(struct inv_t));
        game->inv[i]->item_pick = VIDE;
        game->inv[i]->item = sfSprite_create();
        game->inv[i]->item = set_sprite(VIDE);
    }
    for (int i = 0; i < 11; i++) {
        game->inv[i]->item_pick = i;
        game->inv[i]->item = set_sprite(i);
        item_type(game, i, i);
    }
}
