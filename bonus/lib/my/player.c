/*
** EPITECH PROJECT, 2020
** player
** File description:
** Player's functions
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <stdio.h>


struct match remove_match(struct match map_data, int b, int c)
{
    int a = 0;

    for (a = 0; map_data.map[b - 1][a] != '\0'; a++);
    map_data.left_matches[b - 1] -= c;
    for (a = a - 1; c != 0; a--)
        if (map_data.map[b - 1][a] == '|') {
            map_data.map[b - 1][a] = ' ';
            c--;
        }
    return map_data;
}

int detect_error(struct match map_data, int c, int b)
{
    if (c > map_data.max) {
        my_printf("Error: you cannot remove more ");
        my_printf("than %d matches per turn\n", map_data.max);
        return 0;
    }
    else if (c > map_data.left_matches[b - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return 0;
    }
    else if (c == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return 0;
    }
}

int player_match(struct match map_data, int b, size_t a)
{
    char *str2 = NULL;
    int c = 0;
    int stop = 1;

    while (go_on(map_data, c, b, stop) == 1) {
        my_putstr("Matches: ");
        stop = getline(&str2, &a, stdin);
        c = my_getnbr(str2);
        if (stop == -1)
            return stop;
        else if (c < 0 && (str2[0] < '0' || str2[0] > '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return 0;
        } else
            stop = detect_error(map_data, c, b);
    }
    if (stop == 0)
        return stop;
    else
        return c;
}

int player_line(struct match map_data)
{
    char *str = NULL;
    size_t a = 0;
    int b = 0;
    int c = 0;
    int stop = 0;

    while (b <= 0 || b > map_data.lines || map_data.left_matches[b - 1] == 0) {
        my_putstr("Line: ");
        stop = getline(&str, &a, stdin);
        b = my_getnbr(str);
        if (stop == -1)
            return stop;
        else if (b <= 0 || str[0] <= '0' && str[0] >= '9')
            my_putstr("Error: invalid input (positive number expected)\n");
        else if (b <= 0 || b > map_data.lines ||
                 map_data.left_matches[b - 1] == 0)
            my_putstr("Error: this line is out of range\n");
    }
    return b;
}

struct match player(struct match map_data)
{
    char *str = NULL;
    size_t a = 0;
    int b = 0;
    int c = 0;

    my_putstr("\033[0;32mYour turn:\n");
    while (b == 0 || c == 0) {
        b = player_line(map_data);
        if (b == -1) {
            map_data.turn = -1;
            return map_data;
        }
        c = player_match(map_data, b, a);
        if (c == -1) {
            map_data.turn = -1;
            return map_data;
        }
    }
    my_printf("Player removed %d match(es) from line %d\n", c, b);
    map_data = remove_match(map_data, b, c);
    return map_data;
}