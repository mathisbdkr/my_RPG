/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** item_armor
*/

#include "game_struct.h"
#include "game.h"

static void move_item(struct game_t *game, int i)
{
    shield_upgrade(game);
    sfSprite *tmp = game->inv[i]->item;
    int tmp_type = game->inv[i]->type;
    int id = game->inv[i]->item_pick;
    int tmp_damage = game->inv[i]->damage;
    if (!tmp_damage)
        tmp_damage = 0;
    game->inv[i]->item = game->inv[game->item_pos]->item;
    game->inv[i]->item_pick = game->inv[game->item_pos]->item_pick;
    game->inv[i]->damage = game->inv[game->item_pos]->damage;
    game->inv[i]->type = game->inv[game->item_pos]->type;
    game->inv[game->item_pos]->item = tmp;
    game->inv[game->item_pos]->item_pick = id;
    game->inv[game->item_pos]->type = tmp_type;
    game->inv[game->item_pos]->damage = tmp_damage;
    game->item_pos = -1;
    game->pstat->atk_dammage = 0;
}

static int item_select(struct game_t *game, int i, sfRectangleShape *box,
    int deplace)
{
    int pass = 0;
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(box);
    if (sfFloatRect_contains(&bound, game->mouse_pos.x, game->mouse_pos.y)
    && sfMouse_isButtonPressed(0) && game->item_pos != -1 &&
    (game->inv[game->item_pos]->type == ARMOR ||
    game->inv[game->item_pos]->type == RIEN)) {
        move_item(game, i);
        deplace = -1;pass = 1;
        while (sfMouse_isButtonPressed(0));
    }
    if (sfFloatRect_contains(&bound, game->mouse_pos.x, game->mouse_pos.y)
    && sfMouse_isButtonPressed(0) && pass == 0) {
        deplace = i;
        shield_downgrade(game, i);
        game->pstat->atk_dammage = game->inv[i]->damage;
        while (sfMouse_isButtonPressed(0));
    }
    return deplace;
}

static void change_item(struct game_t *game, int deplace)
{
    if (deplace != -1) {
        game->item_pick = deplace;
        game->item_pos = game->item_pick;
        game->item_pick = -1;
    } else {
        game->item_pick = -1;
    }
}

void item_armor(struct game_t *game, sfVector2f pos)
{
    sfColor color = sfColor_fromRGBA(100, 100, 100, 100);
    int deplace = -1;
    sfRectangleShape *box = made_button(get_position(75, 75),
    get_position(pos.x - 240, pos.y - 115), color);
    pos.y += 85;
    for (int i = NB_INV - 4; i < NB_INV; i++) {
        pos.y += 90;
        sfRectangleShape_setPosition(box, get_position(pos.x - 240,
        pos.y - 115));
        deplace = item_select(game, i, box, deplace);
        sfRenderWindow_drawRectangleShape(game->window, box, 0);
    }
    change_item(game, deplace);
}
