/*
** EPITECH PROJECT, 2023
** test
** File description:
** game
*/

#include <unistd.h>
#include "game.h"
#include "game_struct.h"
#include "my.h"

static void close_win(struct game_t *game, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && game->pause == 0
    && game->new_map == 0) {
        game->pause = 1;
        while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue);
    }
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue && game->pause == 0) {
        game->pause = 2;
        while (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
        game->end = 1;
    }
}

static int change_planet(struct game_t *game)
{
    if (game->new_map > 0) {
        sfVector2u size_win = sfRenderWindow_getSize(game->window);
        sfVector2f size = get_position((size_win.x / 2) - 100, (size_win.y / 2)
        - 75);
        sfFont *font = sfFont_createFromFile("./src/fonts/Starjhol2.ttf");
        sfColor color = sfColor_fromRGBA(100, 100, 100, 255);
        sfText *info = made_txt(txt_travel[game->new_map - 1], size,
        get_position(1,1), font);
        size.x -= 10;
        size.y -= 10;
        made_rond_rect(get_position(420, 100), size, color, game->window);
        sfRenderWindow_drawText(game->window, info, 0);
        sfText_destroy(info);
        sfFont_destroy(font);
        return confirm(game);
    }
    return 0;
}

void moove_map(struct game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->map);
    const sfTexture *texture = sfSprite_getTexture(game->map);
    sfVector2u size = sfTexture_getSize(texture);
    sfVector2u screen = sfRenderWindow_getSize(game->window);
    player_level(game);
    display_level(game);
    if (game->pause == 0) {
        pos = change_coord(pos, size, screen, game);
        if (change_planet(game) == 1) {
            return;
        }
        sfSprite_setPosition(game->map, pos);
        handle_interaction(game);
    }
}

void display_objects(struct win_t *win, struct game_t *game,
    sfEvent event)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_pollEvent(win->window, &event);
    game->event = event;
    sfRenderWindow_drawSprite(game->window, game->map, 0);
    game->mouse_pos = mouse_position(game->window);
    sfRenderWindow_drawSprite(game->window, game->player_sprite, NULL);
    minimap(game);
    close_win(game, event);
    attacks(game);
    moove_map(game);
    pause_game(win, game);
    inventaire(game);
    if (game->index_quest == 1 && game->map_index == 1)
        display_ennemies(game);
    if (QUEST->chat != NULL) {
        sfRenderWindow_drawRectangleShape(game->window, QUEST->chat->rect, 0);
        sfRenderWindow_drawText(game->window, QUEST->chat->text, NULL);
    }
    sfRenderWindow_display(game->window);
}

void game_luncher(struct win_t *win, sfBool is_load)
{
    struct game_t *game = init_game(win);
    if (!game)
        return;
    if (is_load) {
        load_game(game, "save.txt");
        make_game_map(game, game->map_index);
    }
    sfMusic_pause(win->music);
    sfEvent event;
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    game->end = 0;
    while (game->end == 0) {
        sfMusic_setVolume(game->music, win->volume_music);
        display_objects(win, game, event);
    }
    while (sfMouse_isButtonPressed(0) == 1);
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    save_game(game);
}
