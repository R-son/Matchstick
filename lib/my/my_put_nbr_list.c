/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display the number given as parameter
*/

#include <stdarg.h>
#include "../../include/my.h"

int my_put_int_unsigned(va_list ap)
{
    int a;
    unsigned int nb = va_arg(ap, unsigned int);
    char b;

    if (nb > 0) {
        a = nb % 10;
        b = '0' + a;
        nb = (nb - a) / 10;
        my_put_nbr(nb);
        my_putchar(b);
        return (0);
    }
    if (nb < 0) {
        a = -nb;
        my_put_nbr(a);
        return (0);
    }
    return (0);
}

int my_put_nbr_list(va_list ap)
{
    int a;
    int nb = va_arg(ap, int);
    char b;

    if (nb > 0) {
        a = nb % 10;
        b = '0' + a;
        nb = (nb - a) / 10;
        my_put_nbr(nb);
        my_putchar(b);
        return (0);
    }
    if (nb < 0) {
        a = -nb;
        my_putchar('-');
        my_put_nbr(a);
        return (0);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int a;
    char b;

    if (nb > 0) {
        a = nb % 10;
        b = '0' + a;
        nb = (nb - a) / 10;
        my_put_nbr(nb);
        my_putchar(b);
        return (0);
    }
    if (nb < 0) {
        a = -nb;
        my_putchar('-');
        my_put_nbr(a);
        return (0);
    }
    return (0);
}
