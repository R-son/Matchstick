/*
** EPITECH PROJECT, 2020
** my
** File description:
** Contains structures and prototypes
*/

#include <stdarg.h>

#ifndef MAP_H_
#define MAP_H_

struct match
{
    int lines;
    int columns;
    int max;
    int turn;
    char **map;
    int *left_matches;
};



int my_getnbr(char const *str);
int matchstick(struct match map_data);
struct match bot(struct match map_data);
int win(struct match map_data, int turn);
char **map_set(int lines, int columns);
struct match map_fill(struct match map_data);


void my_putchar(char c);
int my_putmap(char const *str);
void map_draw(struct match map_data);
int my_putstr(char const *str);
int my_printf(const char *format, ...);

int flags(char c);
int my_printf_put_str(va_list ap);
int my_putchar_list(va_list ap);
void my_putchar(char c);
int my_put_nbr_list(va_list ap);
int my_put_nbr(int nb);
int my_putstr_list(va_list ap);
int dec_to_oct_unsigned(va_list ap);
int my_put_int_unsigned(va_list ap);
struct match player(struct match map_data);
struct match remove_match(struct match map_data, int b, int c);
int go_on(struct match map_data, int c, int b, int stop);

#endif /*MAP_H_*/
