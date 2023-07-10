/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** load_inv
*/

#include <sys/stat.h>
#include "game.h"
#include "game_struct.h"


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

void load_inv(struct game_t *game, char *str)
{
    char **tab = my_str_to_word_array(str, ',');
    int type = RIEN;
    for (int i = 0; i < NB_INV; i++) {
        game->inv[i]->item_pick = my_getnbr(tab[i]);
        type = game->inv[i]->item_pick;
        game->inv[i]->item = set_sprite(type);
        item_type(game, i, type);
    }
}
