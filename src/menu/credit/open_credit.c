/*
** EPITECH PROJECT, 2023
** merge
** File description:
** open_credit
*/

#include "my.h"

static int len_ligne(char *str)
{
    int nb = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            nb++;
        }
    }
    return nb;
}

static sfText **text_tab(sfVector2f size, sfVector2f
    pos, sfFont *font, char *buf)
{
    int nb = len_ligne(buf);
    char **tab = my_str_to_word_array(buf, '\n');
    sfText **text_tab = malloc(sizeof(sfText *) * nb);
    for (int i = 0; i < nb; i++) {
        text_tab[i] = made_txt(tab[i], pos, size, font);
        sfText_setOrigin(text_tab[i],
        get_position((my_strlen(tab[i]) * 20) / 2.5, 15));
        if (i == 1)
            pos.y += 50;
        if (i == 6) {
            size.x -= 0.2;
            size.y -= 0.2;
            pos.y += 50;
        }
        pos.y += 50;
        size = get_position(size.x + 0.06, size.y + 0.06);
    }
    return text_tab;
}

sfText **open_credit(struct win_t *win, sfVector2f
    size, sfVector2u size_win, sfFont *font)
{
    sfVector2f pos = get_position(size_win.x / 2.1, size_win.y);
    struct stat sb;
    char *path_name = "src/menu/credit/credit.txt";
    stat(path_name, &sb);
    int fd = open(path_name, O_RDONLY);
    char *buf = malloc(sizeof(char) * sb.st_size);
    read(fd, buf, sb.st_size);
    close(fd);
    int nb = 0;
    for (int i = 0; i < sb.st_size; i++) {
        if (buf[i] == '\n') {
            nb++;
        }
    }
    win->nb_ligne_credit = nb;
    return text_tab(size, pos, font, buf);
}
