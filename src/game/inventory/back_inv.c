/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** back_inv
*/

#include "game_struct.h"
#include "my.h"

static void img_back(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfTexture *texture =
    sfTexture_createFromFile("./src/assets/item/fond_inv.png", 0);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, texture, sfNone);
    sfVector2u size = sfTexture_getSize(texture);
    sfSprite_setScale(background, get_position(1.7, 1.55));
    sfSprite_setOrigin(background, get_position(size.x / 2, size.y / 2));
    sfSprite_setPosition(background, get_position((size_win.x / 2) - 100,
    size_win.y / 2));
    sfRenderWindow_drawSprite(game->window, background, 0);
    sfTexture_destroy(texture);
}

static void back_inv(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfRectangleShape *player = made_button(get_position(200, 400),
    get_position(0,0), sfColor_fromRGBA(100, 100, 100, 100));
    sfRectangleShape_setOrigin(player, get_position(100, 200));
    sfRectangleShape_setPosition(player, get_position((size_win.x / 2)
    - 400, size_win.y / 2));
    sfRenderWindow_drawRectangleShape(game->window, player, 0);
    sfRectangleShape_destroy(player);
}

void display_back_inv(struct game_t *game)
{
    img_back(game);
    back_inv(game);
}
