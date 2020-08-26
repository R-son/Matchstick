/*
** EPITECH PROJECT, 2019
** dec_to_oct
** File description:
** Converts decimal integer to octal integer
*/

#include <stdarg.h>
#include "../../include/my.h"

int dec_to_oct_uns_rec(int nbr)
{
    int result = 0;
    char c;

    result = nbr % 8;
    nbr /= 8;
    if (nbr >= 1)
        dec_to_oct_uns_rec(nbr);
    c = result + '0';
    my_putchar(c);
    return (0);
}

int dec_to_oct_unsigned(va_list ap)
{
    int nbr = va_arg(ap, int);
    int result = 0;
    char c;

    result = nbr % 8;
    nbr /= 8;
    if (nbr >= 1)
        dec_to_oct_uns_rec(nbr);
    c = result + '0';
    my_putchar(c);
    return (0);
}
