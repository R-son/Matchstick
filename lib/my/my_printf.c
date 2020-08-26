/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Prints what is asked with flag
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <unistd.h>

int flags(char c)
{
    char const *str = "csSoudi";
    int a = 0;

    for (; str[a] != '\0'; a++) {
        if (c == str[6])
            return (5);
        if (c == str[a])
            return (a);
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int (*flags_select[6])(va_list ap) = {my_putchar_list, my_putstr_list,
    my_printf_put_str, dec_to_oct_unsigned, my_put_int_unsigned,
    my_put_nbr_list};

    va_start(ap, format);
    for (int a = 0; format[a] != '\0'; a++){
        if (format[a] == '%')
            if (format[a + 1] == '%') {
                write(1, &format[a + 1], 1);
                a++;
            } else {
                flags_select[flags(format[a + 1])](ap);
                a++;
            }
        else
            write(1, &format[a], 1);
    }
    va_end(ap);
}
