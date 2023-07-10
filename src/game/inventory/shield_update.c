/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** shield_update
*/

#include "game_struct.h"
#include "game.h"

void shield_downgrade(struct game_t *game, int i)
{
    if (game->inv[i]->item_pick == CHEST_ST)
        game->pstat->shield -= 40;
    if (game->inv[i]->item_pick == LEG_ST)
        game->pstat->shield -= 30;
    if (game->inv[i]->item_pick == FEET_ST)
        game->pstat->shield -= 15;
    if (game->inv[i]->item_pick == HEAD_ST)
        game->pstat->shield -= 15;
}

void shield_upgrade(struct game_t *game)
{
    if (game->inv[game->item_pos]->item_pick == CHEST_ST)
        game->pstat->shield += 40;
    if (game->inv[game->item_pos]->item_pick == LEG_ST)
        game->pstat->shield += 30;
    if (game->inv[game->item_pos]->item_pick == FEET_ST)
        game->pstat->shield += 15;
    if (game->inv[game->item_pos]->item_pick == HEAD_ST)
        game->pstat->shield += 15;
}
