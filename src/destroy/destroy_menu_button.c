/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** destroy_menu_button
*/

#include "menu_struct.h"

void destroy_menu(menu_t *menu)
{
    for (int i = 0; i < NB_BUTTON; i++) {
        sfText_destroy(menu->button[i]->text);
        sfRectangleShape_destroy(menu->button[i]->rect);
    }
}
