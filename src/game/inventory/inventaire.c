/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** inventaire
*/

#include "game.h"
#include "game_struct.h"
#include "my.h"

void item_type(struct game_t *game, int i, int type)
{
    if (type == VIDE) {
        game->inv[i]->type = RIEN;
        game->inv[i]->damage = 0 + game->pstat->total_atk;
    }
    if (type >= BLASTER1 && type <= BLASTER2) {
        game->inv[i]->type = GUN;
        game->inv[i]->damage = 7 + game->pstat->total_atk;
    }
    if (type >= SABRE && type <= SABRE3) {
        game->inv[i]->type = SWORD;
        game->inv[i]->damage = 10 + game->pstat->total_atk;
    }
    if (type >= FEET_ST && type <= HEAD_ST) {
        game->inv[i]->type = ARMOR;
        game->inv[i]->damage = 0 + game->pstat->total_atk;
    }
}

static sfVector2f change_pos(int nb_ligne, sfVector2f pos, int i)
{
    if (i % nb_ligne == 0 && i > 2 && i < NB_INV - 4) {
        pos.y += 85;
        pos.x -= 85 * nb_ligne;
    }
    if (i == NB_INV - 10 && i < NB_INV - 4)
        pos.y += 45;
    if (i == NB_INV - 4) {
        pos.x -= 6 * 85 + 202;
        pos.y -= 3 * 85 + 32;
    }
    return pos;
}

static void display_inv(struct game_t *game, sfVector2f pos)
{
    int nb_ligne = 6;
    for (int i = 0; i < NB_INV; i++) {
        pos = change_pos(nb_ligne, pos, i);
        sfSprite_setPosition(game->inv[i]->item, pos);
        if (game->item_pos == i)
            sfSprite_setPosition(game->inv[i]->item, game->mouse_pos);
        sfRenderWindow_drawSprite(game->window, game->inv[i]->item, 0);
        if (i < NB_INV - 4)
            pos.x += 85;
        else
            pos.y += 90;
    }
}

void inventaire(struct game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue
    || (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue && game->pause == 2)) {
        game->pause = 0;
        while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue
        || sfKeyboard_isKeyPressed(sfKeyI) == sfTrue);
    }
    if (game->pause == 2) {
        display_back_inv(game);
        sfVector2u size_win = sfRenderWindow_getSize(game->window);
        sfVector2f pos = get_position(size_win.x / 2, size_win.y / 2);
        display_stat(game);
        pos.x -= 200;
        pos.y -= 150;
        display_item_box(game, get_position(pos.x, pos.y - 85));
        display_inv(game, pos);
    } else {
        inv_bare(game);
    }
}
