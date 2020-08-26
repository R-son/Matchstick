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
    int a;

    my_putchar('*');
    for (a = 0; str[a] != '\0'; a++)
            my_putchar(str[a]);
    my_putchar('*');
    my_putchar('\n');
    return (0);
}

int my_putstr(char const *str)
{
    int a;

    for (a = 0; str[a] != '\0'; a++)
            my_putchar(str[a]);
    return (0);
}