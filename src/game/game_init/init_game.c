/*
** EPITECH PROJECT, 2023
** test
** File description:
** init_game
*/

#include "game_struct.h"
#include "game.h"
#include "my.h"

void make_game_map(struct game_t *game, int nb)
{
    sfSprite *background = sfSprite_create();
    sfMusic_stop(game->music);
    game->texture_back_map = sfTexture_createFromFile
    (back_map_path[nb], NULL);
    sfTexture *texture = sfTexture_createFromFile
        (map_path[nb], NULL);
    if (game->index_quest == 1 && nb == 1) {
        texture = sfTexture_createFromFile
        ("map/tatooine_quest_one.png", NULL);
    }
    sfSprite_setTexture(background, texture, 0);
    sfSprite_setTexture(game->minimap->minimap, texture, 0);
    sfSprite_setScale(background, get_position(2, 2));
    sfSprite_setPosition(background, start_coord[nb]);
    game->map = background;
    game->map_index = nb;
    game->music = sfMusic_createFromFile(map_music[nb]);
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
}

static quest_t **init_quest(void)
{
    quest_t **quest = malloc(sizeof(quest_t *) * (NB_QUEST));
    int i = 0;

    for (; i < NB_QUEST; i++) {
        quest[i] = malloc(sizeof(quest_t));
        quest[i]->index_dialogue = 0;
        quest[i]->file = file_to_arr(quest_file[i]);
        quest[i]->chat = NULL;
    }
    quest[i] = NULL;

    return quest;
}

static void init_game_pt2(struct game_t *game)
{
    game->item_pick = -1;
    game->item_pos = -1;
    game->end = 0;
    game->pause = 0;
    game->new_map = 0;
    game->map_index = 0;
    game->item_select = 0;
    game->frame = 0;
    game->index_quest = 0;
    game->direction = 0;
}

static void init_sprites(struct game_t *game)
{
    init_attack(game);
    init_kaelan(game);
    init_strom_troops(game);
    init_game_pt2(game);
}

struct game_t *init_game(struct win_t *win)
{
    struct game_t *game = malloc(sizeof(struct game_t));
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    game->window = win->window;
    init_sprites(game);
    game->pos_player = get_position((size_window.x / 2), size_window.y / 2);
    game->music = sfMusic_createFromFile(map_music[0]);
    game->minimap = malloc(sizeof(struct minimap_t));
    game->minimap->minimap = sfSprite_create();
    sfSprite_setPosition(game->player_sprite, game->pos_player);
    game->clock = sfClock_create();
    game->quest = init_quest();
    game->inv = malloc(sizeof(struct inv_t));
    game->pstat = init_player_stat();
    game->ennemies = init_ennemies(0);
    init_inv(game);
    make_game_map(game, 0);
    return game;
}
