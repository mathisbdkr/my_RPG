/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** punbr
*/

#include <unistd.h>

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int my_put_nbr(int nb, int fd)
{
    int result = 0;
    if (nb < 0) {
        nb = nb * - 1;
        my_putchar('-', fd);
    }
    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + '0', fd);
    }
    if (nb > 9) {
        result = nb % 10;
        my_put_nbr(nb / 10, fd);
        my_put_nbr(result, fd);
    }
    return nb;
}
