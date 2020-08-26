/*
** EPITECH PROJECT, 2020
** map
** File description:
** Fills matchstick's map
*/

#include "../../include/my.h"
#include <stdlib.h>

int go_on(struct match map_data, int c, int b, int stop)
{
    if ((c <= 0 || c > map_data.left_matches[b - 1]
    || c > map_data.max) && stop != 0)
        return 1;
    return 0;
}

void map_draw(struct match map_data)
{
    my_putstr("\033[0;34m");
    for (int b = 0; b != map_data.columns + 2; b++)
        my_putchar('*');
    my_putchar('\n');
    for (int a = 0; a != map_data.lines; a++)
        my_putmap(map_data.map[a]);
    my_putstr("\033[0;34m");
    for (int b = 0; b != map_data.columns + 2; b++)
        my_putchar('*');
    my_putstr("\033[0m");
    my_putstr("\n\n");
}

struct match map_fill(struct match map_data)
{
    int c = 0;

    map_data.map = malloc(sizeof(char *) * map_data.lines + 1);
    for (int a = 0; a != map_data.lines; a++) {
        map_data.map[a] = malloc(sizeof(char) * map_data.columns + 1);
        for (int b = 0; b != map_data.columns; b++) {
            c = (map_data.columns - 1) / 2;
            if (b >= c - a && b <= c + a)
                map_data.map[a][b] = '|';
            else
                map_data.map[a][b] = ' ';
        }
    }
    map_data.left_matches = malloc(sizeof(int *) * map_data.lines + 1);
    for (int a = 0, c = 0; a != map_data.lines; a++, c++)
        map_data.left_matches[a] = 1 + (c * 2);
    return map_data;
}

int matchstick(struct match map_data)
{
    int a = 0;

    while (a != 1 && a != 2) {
        map_data = player(map_data);
        if (map_data.turn == -1) {
            my_putstr("\033[0m");
            return 0;
        }
        map_draw(map_data);
        map_data.turn = 2;
        a = win(map_data, map_data.turn);
        if (a == 0) {
            my_putstr("\033[0;35m");
            map_data = bot(map_data);
            my_putstr("\033[0m");
            map_draw(map_data);
            map_data.turn = 1;
            a = win(map_data, map_data.turn);
        }
    }
    return a;
}