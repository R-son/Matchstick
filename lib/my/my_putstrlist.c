/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays character strings
*/

#include "../../include/my.h"
#include <stdarg.h>

int my_putstr_list(va_list ap)
{
    char *str = va_arg(ap, char *);
    int a;

    for (a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}