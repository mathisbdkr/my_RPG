/*
** EPITECH PROJECT, 2023
** test
** File description:
** volume_bare
*/

#include "my.h"

void volume_bare(struct win_t *win)
{
    sfVector2f pos = get_position(260, 200);
    for (int i = 0; i < 3; i++) {
        create_box(win, pos);
        center_bare(win, pos);
        curseur_bare(win, pos, i);
        pos.y += 100;
    }
}
