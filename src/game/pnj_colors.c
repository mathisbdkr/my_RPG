/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** pnj_colors
*/

#include "game.h"
#include "game_struct.h"

sfColor init_pnj_color(void)
{
    sfColor pnj_color = {0};

    pnj_color.a = 255;
    pnj_color.b = 255;
    pnj_color.g = 0;
    pnj_color.r = 173;

    return pnj_color;
}
