/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** init_ennemies
*/

#include "game.h"
#include "game_struct.h"

struct attacks_t init_ennemies_attack(struct game_t *game)
{
    struct attacks_t atk = {0};

    atk.weapon_texture =
    sfTexture_createFromFile("./src/assets/item/sabre_sith.png", 0);
    atk.weapon_sprite = sfSprite_create();
    sfVector2u size_win = sfRenderWindow_getSize(game->window);
    atk.weapon_pos = (sfVector2f) {size_win.x / 2, size_win.y / 2};
    atk.weapon_scl = (sfVector2f) {0.6, 0.6};
    sfSprite_setTexture(atk.weapon_sprite, atk.weapon_texture, 0);
    sfSprite_setScale(atk.weapon_sprite, atk.weapon_scl);
    sfSprite_setRotation(atk.weapon_sprite, 180);
    atk.mode = 0;
    atk.anim = 0;
    atk.direction = 0;

    return atk;
}

struct s_ennemies *init_ennemies(int quest)
{
    struct s_ennemies *ennemies = malloc(sizeof(struct s_ennemies));

    ennemies->ennemies = sfSprite_create();
    ennemies->ennemies_texture = sfTexture_createFromFile(ennemy_file[quest],
        NULL);
    ennemies->life = 100;
    ennemies->square = init_rectangle((sfVector2f){100, 0},
        (sfVector2f){100, 20}, sfBlack, sfBlack);
    ennemies->name_case = init_rectangle((sfVector2f){0, 100},
        (sfVector2f){110, 20}, sfBlack, sfBlack);
    ennemies->filled_life = init_rectangle((sfVector2f){100, 0},
        (sfVector2f){100, 20}, sfRed, sfTransparent);
    sfSprite_setTexture(ennemies->ennemies, ennemies->ennemies_texture, 0);
    ennemies->name = init_text(ennemy_name[quest], 2, (sfVector2f){0, 100}, 15);
    ennemies->pos.x = 0;
    ennemies->pos.y = 0;
    ennemies->atk_dmg = quest + 10;
    sfSprite_setPosition(ennemies->ennemies, ennemies->pos);
    sfText_setColor(ennemies->name, sfYellow);
    return ennemies;
}
