/*
** EPITECH PROJECT, 2019
** my_printf_put_str
** File description:
** made for the %S flag
*/

#include <stdarg.h>
#include "../../include/my.h"

int my_printf_put_str(va_list ap)
{
    char *str = va_arg(ap, char *);

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < 32 || str[a] > 127)
            my_putchar('\\');
        else
            my_putchar(str[a]);
    }
    return (0);
}
