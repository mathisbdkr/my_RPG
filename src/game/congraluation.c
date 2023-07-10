/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** congraluation
*/

#include "game.h"
#include "game_struct.h"

void congraluation(struct game_t *game)
{
    sfVector2f pos = {0.0, 0.0};
    sfVertexArray **vertexArray = malloc(sizeof(sfVertexArray *) * NB_STAR);

    srand(time(NULL));
    for (int i = 0; i <= NB_STAR; i++) {
        vertexArray[i] = sfVertexArray_create();
        pos.x = rand() % 1920;
        pos.y = rand() % 1080;
        sfVertex vertex = {pos, sfWhite, {10, 10}};
        sfVertexArray_append(vertexArray[i], vertex);
        sfRenderWindow_drawVertexArray(game->window, vertexArray[i], NULL);
    }
    sfRenderWindow_display(game->window);
}
