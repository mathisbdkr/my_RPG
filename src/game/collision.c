/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** collision
*/

#include "game.h"
#include "game_struct.h"

static int check_key(int key)
{
    if (key == sfKeyZ) {
        return 0;
    }
    if (key == sfKeyS) {
        return 35;
    }
    if (key == sfKeyQ) {
        return -5;
    }
    if (key == sfKeyD) {
        return 32;
    }
    return 0;
}

int is_color_is(sfColor color_a, sfColor color_b)
{
    if ((color_a.r == color_b.r
        && color_a.g == color_b.g
        && color_a.b == color_b.b)) {
            return 1;
    }
    return 0;
}

sfColor wall_colision(struct game_t *game, sfImage *back_map,
    int pixel_to_check)
{
    sfColor color_to_go = sfTransparent;
    sfVector2f pos = sfSprite_getPosition(game->map);
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    pos.y *= -0.5;
    pos.x *= -0.5;

    if (pixel_to_check == 32 || pixel_to_check == 5) {
        color_to_go = sfImage_getPixel(back_map,
            (unsigned int)(pos.x + (size_win.x / 4)) + pixel_to_check,
            (unsigned int)(pos.y + (size_win.y / 4) + 30));
    } else if (pixel_to_check == 35 || pixel_to_check == 0) {
        color_to_go = sfImage_getPixel(back_map,
            (unsigned int)(pos.x + (size_win.x / 4)),
            (unsigned int)pos.y + (size_win.y / 4) + pixel_to_check);
    }

    return color_to_go;
}

static sfColor handle_mouvement_on_map(struct game_t *game, sfImage *back_map,
    int pixel_to_check)
{
    sfColor color_to_go = wall_colision(game, back_map, pixel_to_check);
    if (is_color_is(color_to_go, sfRed))
        game->new_map = 2;
    if (is_color_is(color_to_go, sfBlue))
        game->new_map = 3;
    if (is_color_is(color_to_go, sfGreen))
        game->new_map = 4;
    if (is_color_is(color_to_go, sfColor_fromRGB(255,77,77)))
        game->new_map = 1;

    return color_to_go;
}

void check_collision(struct game_t *game, int key)
{
    animate_sprite(game->player_sprite, game->clock, &game->frame,
    game->direction);
    sfImage *back_map = sfTexture_copyToImage(game->texture_back_map);
    int pixel_to_check = check_key(key);
    sfColor color_to_go = sfTransparent;
    if (key == sfKeyQ || key == sfKeyZ) {
        pixel_to_check *= -1;
    }
    color_to_go = handle_mouvement_on_map(game, back_map, pixel_to_check);
    if (is_color_is(color_to_go, sfBlack)) {
        game->speed = 0;
    } else if (sfKeyboard_isKeyPressed(sfKeyLShift)){
        game->speed = 6;
    } else {
        game->speed = 4;
    }
    sfImage_destroy(back_map);
}
