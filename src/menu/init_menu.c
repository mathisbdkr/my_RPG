/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu_struct.h"

static button_t **init_button(void)
{
    button_t **button = malloc(sizeof(button_t) * NB_BUTTON);

    for (int i = 0; i < NB_BUTTON; i++) {
        button[i] = malloc(sizeof(button_t));
        button[i]->pos = position_button[i];
        button[i]->size = (sfVector2f){250.0, 50.0};
        button[i]->rect = init_rectangle(position_button[i], button[i]->size,
            sfTransparent, sfBlack);
        button[i]->pos.x += 20;
        button[i]->text = init_text(text_button[i], 2, button[i]->pos, 35);
    }

    return button;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    sfIntRect *size = malloc(sizeof(sfIntRect));
    size->height = 1029;
    size->width = 1920;
    size->left = 0;
    size->top = 0;
    menu->button = init_button();
    menu->background = sfSprite_create();
    menu->texture_background = sfTexture_createFromFile
        ("src/assets/coruscant.jpg", size);
    sfSprite_setPosition(menu->background, (sfVector2f){0, 0});
    sfSprite_setTexture(menu->background, menu->texture_background, sfTrue);
    menu->menu_window = sfRenderWindow_create((sfVideoMode){1910, 1020, 32},
        "rpg", sfClose | sfResize,  NULL);
    sfRenderWindow_setFramerateLimit(menu->menu_window, 75);
    sfRenderWindow_setMouseCursorVisible(menu->menu_window, sfFalse);
    return menu;
}
