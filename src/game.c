/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** game
*/

#include <stdlib.h>
#include "menu_struct.h"

int game(void)
{
    menu_t *menu = init_menu();
    display_menu(menu);

    return 0;
}
