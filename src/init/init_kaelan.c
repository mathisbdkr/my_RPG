/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_kaelan.c
*/

#include "game.h"
#include "game_struct.h"
#include "my.h"

void animate_sprite(sfSprite *sprite, sfClock *clock, int *frame, int direction)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 100) {
        *frame = (*frame + 1) % 3;
        int row = 0;
        if (direction == 0)
            row = 0;
        if (direction == 3)
            row = 1;
        if (direction == 2)
            row = 2;
        if (direction == 1)
            row = 3;
        sfSprite_setTextureRect(sprite, (sfIntRect){*frame * FRAME_WIDTH,
        row * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT});
        sfClock_restart(clock);
    }
}

void init_kaelan(struct game_t *game)
{
    sfTexture *player_texture = sfTexture_createFromFile(KAELAN, NULL);

    game->player_sprite = sfSprite_create();
    sfSprite_setTexture(game->player_sprite, player_texture, sfTrue);
    sfSprite_setPosition(game->player_sprite, game->pos_player);
    sfSprite_setTextureRect(game->player_sprite,
    (sfIntRect){ 0, 0, FRAME_WIDTH, FRAME_HEIGHT });
    sfSprite_setScale(game->player_sprite, get_position(2, 2));
}
