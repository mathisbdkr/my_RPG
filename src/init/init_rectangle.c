/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

sfRectangleShape *init_rectangle(sfVector2f pos, sfVector2f size,
    sfColor color_in, sfColor color_out)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setFillColor(rectangle, color_in);
    sfRectangleShape_setOutlineThickness(rectangle, 1.2);
    sfRectangleShape_setOutlineColor(rectangle, color_out);

    return rectangle;
}
