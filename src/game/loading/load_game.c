/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** load_game
*/

#include <sys/stat.h>
#include "game.h"
#include "game_struct.h"

void free_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }

    free(arr);
}

void get_stat(char **arr, struct game_t *game)
{
    game->pstat->xp = my_getnbr(arr[6]);
    game->pstat->life = my_getnbr(arr[7]);
    game->pstat->total_atk = my_getnbr(arr[8]);
    game->pstat->shield = my_getnbr(arr[9]);
    game->pstat->level = my_getnbr(arr[10]);
}

void load_game(struct game_t *game, char *filepath)
{
    struct stat data;
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    char **arr = NULL;

    stat(filepath, &data);
    buffer = malloc(sizeof(char) * (data.st_size + 1));
    read(fd, buffer, data.st_size);
    buffer[data.st_size] = '\0';
    arr = my_str_to_word_array(buffer, ':');
    game->index_quest = my_getnbr(arr[1]);
    QUEST->index_dialogue = my_getnbr(arr[2]);
    game->map_index = my_getnbr(arr[3]);
    game->pos_player.x = my_getnbr(arr[4]);
    game->pos_player.y = my_getnbr(arr[5]);
    get_stat(arr, game);
    close(fd);
    free(buffer);
}
