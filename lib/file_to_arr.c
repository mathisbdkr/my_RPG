/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** file_to_arr
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char *s1);

static int nb_line(char *const filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *line = NULL;
    size_t len = {0};
    int i = 0;

    while (getline(&line, &len, fd) != -1) {
        i++;
    }
    fclose(fd);
    return i;
}

char **file_to_arr(char *const filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *line = NULL;
    size_t len = {0};
    char **arr = malloc(sizeof(char *) * (nb_line(filepath) + 1));
    int i = 0;

    while (getline(&line, &len, fd) != -1) {
        arr[i] = my_strdup(line);
        i++;
    }
    arr[i] = NULL;
    fclose(fd);

    return arr;
}
