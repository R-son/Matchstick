/*
** EPITECH PROJECT, 2019
** My_putchar
** File description:
** Displays a character
*/

#include <unistd.h>
#include <stdarg.h>

int my_putchar_list(va_list ap)
{
    char c = va_arg(ap, int);
    write(1, &c, 1);
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
