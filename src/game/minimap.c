/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** minimap
*/

#include "game.h"
#include "game_struct.h"

static void is_active(struct game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyM) == sfTrue) {
        if (game->minimap->active == 0)
            game->minimap->active = 1;
        else
            game->minimap->active = 0;
    }
}

static void change_player(struct game_t *game, sfVector2f scale)
{
    sfVector2f scale_save = sfSprite_getScale(game->player_sprite);
    sfVector2u win_size = sfRenderWindow_getSize(game->window);
    sfVector2f pos = sfSprite_getPosition(game->map);
    sfVector2f posi = sfSprite_getPosition(game->player_sprite);
    pos.x *= -(scale.x / 2);
    pos.y *= -(scale.y / 2);
    sfSprite_setScale(game->player_sprite, get_position(1, 1));
    sfVector2f test = get_position((pos.x + (win_size.x / 16) - 15),
    (pos.y + (win_size.y / 16)) - 25);
    sfSprite_setPosition(game->player_sprite, get_position(test.x, test.y));
    sfRenderWindow_drawSprite(game->window, game->player_sprite, 0);
    sfSprite_setScale(game->player_sprite, scale_save);
    sfSprite_setPosition(game->player_sprite, posi);
}

void minimap(struct game_t *game)
{
    is_active(game);
    if (game->minimap->active == 1) {
        sfSprite *map = sfSprite_copy(game->minimap->minimap);
        const sfTexture *texture = sfSprite_getTexture(map);
        sfVector2u size = sfTexture_getSize(texture);
        sfVector2u win_size = sfRenderWindow_getSize(game->window);
        float scale_factor_x = (float)win_size.x / size.x;
        float scale_factor_y = (float)win_size.y / size.y;
        sfVector2f scale = {scale_factor_x / 4, scale_factor_y / 4};
        made_rond_rect(get_position((size.x * scale.x) - 20, (size.y * scale.y)
        - 20), get_position(10, 10), sfBlack, game->window);
        sfSprite_setScale(map, scale);
        sfSprite_setPosition(map, get_position(0, 2));
        sfRenderWindow_drawSprite(game->window, map, 0);
        change_player(game, scale);
        sfSprite_destroy(map);
    }
}
