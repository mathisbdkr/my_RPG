/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** const_inv
*/

#include "game.h"
#include "game_struct.h"

static void hand_item(struct game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        game->item_select++;
    }
    if (game->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        game->item_select--;
    }
    if (game->item_select < 0)
        game->item_select = 5;
    if (game->item_select >= 6)
        game->item_select = 0;
}

void inv_bare_box(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f pos = get_position((size_win.x / 2) - 85 * 2, size_win.y - 50);
    sfColor color = sfColor_fromRGBA(100, 100, 100, 100);
    sfColor color_pick = sfColor_fromRGBA(200, 255, 200, 100);
    sfRectangleShape *box = made_button(get_position(75, 75),
    get_position(pos.x - 37.5, pos.y - 37.5), color);
    for (int i = NB_INV - 10; i < NB_INV - 4; i++) {
        sfRectangleShape_setPosition(box, get_position(pos.x - 37.5,
        pos.y - 37.5));
        if (game->item_select + (NB_INV - 10) == i)
            sfRectangleShape_setFillColor(box, color_pick);
        else
            sfRectangleShape_setFillColor(box, color);
        sfRenderWindow_drawRectangleShape(game->window, box, 0);
        sfSprite_setPosition(game->inv[i]->item, pos);
        if (game->item_pos == i)
            sfSprite_setPosition(game->inv[i]->item, game->mouse_pos);
        sfRenderWindow_drawSprite(game->window, game->inv[i]->item, 0);
        pos.x += 85;
    }
}

void inv_bare(struct game_t *game)
{
    hand_item(game);
    inv_bare_box(game);
}
