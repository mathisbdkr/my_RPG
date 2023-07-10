/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** save_game
*/

#include <fcntl.h>
#include <unistd.h>
#include "game.h"
#include "game_struct.h"

int my_strlen(char const* str);

static void my_dputs(char *const str, int const fd)
{
    write(fd, str, my_strlen(str));
}

static void save_inv(struct game_t *game, int fd)
{
    my_dputs("INV:", fd);
    my_put_nbr(game->inv[0]->item_pick, fd);
    for (int i = 1; i < NB_INV; i++) {
        my_dputs(",", fd);
        my_put_nbr(game->inv[i]->item_pick, fd);
    }
    my_dputs("\n", fd);
}

static void save_stat(struct game_t *game, int fd)
{
    my_dputs("LEVEL:", fd);
    my_put_nbr(game->pstat->level, fd);
    my_dputs("\n", fd);
    my_dputs("XP:", fd);
    my_put_nbr(game->pstat->xp, fd);
    my_dputs("\n", fd);
    my_dputs("SHIELD:", fd);
    my_put_nbr(game->pstat->shield, fd);
    my_dputs("\n", fd);
    my_dputs("LIFE:", fd);
    my_put_nbr(game->pstat->life, fd);
    my_dputs("\n", fd);
}

void save_game(struct game_t *game)
{
    int fd = open("save.txt", O_TRUNC | O_CREAT | O_RDWR, 422);

    my_dputs("QUEST:", fd);
    my_put_nbr(game->index_quest, fd);
    my_dputs("\n", fd);
    my_dputs("DIALOG:", fd);
    my_put_nbr(QUEST->index_dialogue, fd);
    my_dputs("\n", fd);
    my_dputs("MAP:", fd);
    my_put_nbr(game->map_index, fd);
    my_dputs("\n", fd);
    my_dputs("POS:", fd);
    my_put_nbr((int)game->pos_player.x, fd);
    my_dputs(":", fd);
    my_put_nbr((int)game->pos_player.y, fd);
    my_dputs("\n", fd);
    save_inv(game, fd);
    save_stat(game, fd);
    close(fd);
}
