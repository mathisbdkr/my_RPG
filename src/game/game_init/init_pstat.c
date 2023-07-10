/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_pstat
*/

#include "game_struct.h"
#include "game.h"

struct player_stat_t *init_player_stat(void)
{
    struct player_stat_t *pstat = malloc(sizeof(struct player_stat_t));
    pstat->xp = 0;
    pstat->life = 100;
    pstat->atk_dammage = 0;
    pstat->shield = 0;
    pstat->level = 0;
    pstat->total_atk = 0;
    return pstat;
}
