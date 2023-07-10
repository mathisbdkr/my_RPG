/*
** EPITECH PROJECT, 2023
** bsrpg
** File description:
** main
*/

#include <stddef.h>
#include "my_rpg.h"

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL) {
        return 84;
    }
    return game();
}
