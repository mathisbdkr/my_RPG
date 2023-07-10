/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** interaction
*/

#include "game.h"
#include "game_struct.h"

static void change_map(struct game_t *game)
{
    if (game->ennemies->life <= 0) {
        for (int i = 0; i < rand() % 10; i++) {
            game->pstat->xp += rand() % 100;
        }
        sfTexture *map = sfTexture_createFromFile
            ("map/tatooine_quest_one_end.png", NULL);
        sfSprite_setTexture(game->map, map, sfFalse);
        game->ennemies->life = 0;
    }
}

static void init_dialoge(struct game_t *game)
{
    QUEST->chat = malloc(sizeof(struct s_chatbox));
    QUEST->chat->pos = (sfVector2f){40, 150};
    QUEST->chat->rect = init_rectangle(QUEST->chat->pos,
        (sfVector2f){1800, 200}, sfYellow, sfBlack);
    QUEST->chat->text = init_text(QUEST->file[QUEST->index_dialogue],
        2, QUEST->chat->pos, 50);
    sfRectangleShape_setOutlineThickness(QUEST->chat->rect, 2.0);
    sfText_setColor(QUEST->chat->text, sfBlack);
}

static void interaction_npc(struct game_t *game)
{
    sfImage *map = sfTexture_copyToImage(game->texture_back_map);
    sfVector2f pos = sfSprite_getPosition(game->map);
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfColor color = sfWhite;
    sfColor pnj_color = init_pnj_color();
    pos.y *= -0.5;
    pos.x *= -0.5;
    color = sfImage_getPixel(map,
            (unsigned int)(pos.x + (size_win.x / 4)),
            (unsigned int)(pos.y + (size_win.y / 4) - 60));
    if (QUEST->file[QUEST->index_dialogue] == NULL) {
        QUEST->index_dialogue = 0;
        game->index_quest++;
        game->pstat->xp += 100;
    }
    if (is_color_is(color, pnj_color)) {
        init_dialoge(game);
        QUEST->index_dialogue++;
    } else {
        QUEST->chat = NULL;
    }
}

static void handle_attack(struct game_t *game, int factor)
{
    sfImage *map = sfTexture_copyToImage(game->texture_back_map);
    sfVector2f pos = sfSprite_getPosition(game->map);
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfColor color = sfWhite;
    sfColor pnj_color = init_pnj_color();
    pos.y *= -0.5;
    pos.x *= -0.5;
    color = sfImage_getPixel(map,
            (unsigned int)(pos.x + (size_win.x / 4)),
            (unsigned int)(pos.y + (size_win.y / 4)));
    if (QUEST->file[QUEST->index_dialogue] == NULL) {
        QUEST->index_dialogue = 0;
        game->index_quest++;
    }
    if (is_color_is(color, pnj_color) && game->ennemies->life > 0) {
        game->ennemies->life -= 10 * factor;
        sfRectangleShape_setSize(game->ennemies->filled_life,
            (sfVector2f){game->ennemies->life, 20});
    }
    change_map(game);
}

void handle_interaction(struct game_t *game)
{
    if (QUEST == NULL) {
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && game->event.type == sfEvtKeyPressed) {
        interaction_npc(game);
    }
    if (sfKeyboard_isKeyPressed(sfKeyG) && game->event.type == sfEvtKeyPressed) {
        handle_attack(game, 1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyF) && game->event.type == sfEvtKeyPressed) {
        handle_attack(game, 2);
    }
}
