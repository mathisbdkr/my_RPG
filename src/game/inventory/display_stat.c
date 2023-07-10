/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** display_stat
*/

#include "game.h"
#include "game_struct.h"

static char* my_getchar(int num)
{
    int i = 0;
    int tmp = num;
    if (tmp == 0)
        return "0";
    while (tmp > 0) {
        tmp /= 10;
        i++;
    }
    char* str = malloc(sizeof(char) * (i + 1));
    str[i--] = '\0';
    while (num > 0) {
        str[i--] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}

static void xp_bare(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f pos_bare = get_position(size_win.x / 2 - 200, 60);
    sfColor transparent = sfColor_fromRGBA(0, 0, 0, 0);
    sfColor xp = sfColor_fromRGB(100, 100, 255);
    sfRectangleShape *bare = sfRectangleShape_create();

    bare = made_button(get_position(400, 5), pos_bare, transparent);
    sfRenderWindow_drawRectangleShape(game->window, bare, 0);

    bare = made_button(get_position(game->pstat->xp * 4, 5), pos_bare, xp);
    sfRenderWindow_drawRectangleShape(game->window, bare, 0);
}

void display_level(struct game_t *game)
{
    sfFont *font = sfFont_createFromFile("src/fonts/Starjhol2.ttf");
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    char *str = my_strcat("you are level : ", my_getchar(game->pstat->level));
    sfVector2f pos = get_position((size_win.x / 2) -
    (my_strlen(str) * 30) / 2, 0);
    sfText *txt = made_txt(str, pos, get_position(1.5, 1.5), font);
    sfText_setLetterSpacing(txt, 1);
    sfRenderWindow_drawText(game->window, txt, 0);
    xp_bare(game);
    sfFont_destroy(font);
}

void display_stat(struct game_t *game)
{
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    sfVector2f pos = get_position(size_win.x / 2 + 350, size_win.y / 2 - 200);
    sfFont *font = sfFont_createFromFile("src/fonts/Starjhol2.ttf");
    sfText *txt = sfText_create();
    sfColor color = sfColor_fromRGB(100, 100, 100);
    made_rond_rect(get_position(300, 360),
    get_position(pos.x, pos.y + 20), color, game->window);
    int stat[4] = {game->pstat->life, game->pstat->xp,
    game->pstat->atk_dammage + game->pstat->total_atk, game->pstat->shield};
    for (int i = 0; i < NB_STATS; i++) {
        txt = made_txt(stat_txt[i], pos, get_position(1, 1), font);
        sfRenderWindow_drawText(game->window, txt, 0);
        pos.y += 40;
        txt = made_txt(my_getchar(stat[i]), pos, get_position(1, 1), font);
        sfRenderWindow_drawText(game->window, txt, 0);
        pos.y += 65;
    }
    sfText_destroy(txt);
    sfFont_destroy(font);
}
