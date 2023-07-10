/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** chargement
*/

#include "game_struct.h"
#include "my.h"

static sfSprite *fond(struct game_t *game)
{
    sfSprite *back = sfSprite_create();
    game->new_map -= 1;
    sfTexture *texture = sfTexture_createFromFile(load_back[game->new_map], 0);
    sfSprite_setTexture(back, texture, 0);
    return back;
}

void chargement(struct game_t *game)
{
    sfSprite *fond_load = fond(game);
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f size = get_position(size_win.x, 5);
    sfVector2f pos = get_position((float)(size_win.x) * -1, size_win.y - 10);
    sfRectangleShape *load_bare = made_button(size, pos, sfBlue);
    int progress = 0;
    while (pos.x < 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        srand(time(NULL));
        progress = rand() % 10;
        if (progress <= 3)
            progress = 3;
        pos.x += progress;
        sfRectangleShape_setPosition(load_bare, pos);
        sfRenderWindow_drawSprite(game->window, fond_load, 0);
        sfRenderWindow_drawRectangleShape(game->window, load_bare, 0);
        congraluation(game);
        sfRenderWindow_display(game->window);
    }
    sfSprite_destroy(fond_load);
}
