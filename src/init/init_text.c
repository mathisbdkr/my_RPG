/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_text
*/

#include "menu_struct.h"

sfText *init_text(char *str, int kind, sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(fonts_path[kind]);

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);

    return text;
}
