/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays character strings
*/

#include "../../include/my.h"
#include <stdarg.h>

int my_putmap(char const *str)
{
    int a = 0;

    my_putstr("\033[0;34m");
    my_putchar('*');
    my_putstr("\033[1;31m");
    for (a = 0; str[a] != '\0'; a++)
            my_putchar(str[a]);
    my_putstr("\033[0;34m");
    my_putchar('*');
    my_putchar('\n');
    return (0);
}

int my_putstr(char const *str)
{
    int a = 0;

    for (a = 0; str[a] != '\0'; a++)
            my_putchar(str[a]);
    return (0);
}