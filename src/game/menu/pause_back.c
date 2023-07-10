/*
** EPITECH PROJECT, 2023
** test
** File description:
** pause_back
*/

#include "game_struct.h"
#include "my.h"

void pause_background(struct game_t *game, sfVector2f size_back)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    size_back.x -= 50;
    size_back.y -= 50;
    sfVector2f posi_back = get_position((size_win.x / 2) - size_back.x / 2,
    (size_win.y / 2) - size_back.y / 2);
    sfColor color = sfColor_fromRGBA(150, 150, 150, 255);
    made_rond_rect(size_back, posi_back, color, game->window);
}
