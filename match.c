/*
** EPITECH PROJECT, 2020
** match
** File description:
** Matchstick's main functions
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <time.h>

void winner(int turn)
{
    if (turn == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    else if (turn == 2)
        my_putstr("You lost, too bad...\n");
}

int win(struct match map_data, int turn)
{
    int matches = 0;

    for (int a = 0; a != map_data.lines; a++)
        matches += map_data.left_matches[a];
    if (matches == 0) {
        winner(turn);
        return turn;
    }
    return 0;
}

struct match bot(struct match map_data)
{
    int a = 0;
    int b = 0;
    time_t t;

    srand((unsigned) time(&t));
    while (a == 0 || b == 0 || b > map_data.max) {
        a = rand();
        a %= map_data.lines + 1;
        a = (a < 0) ? -a : a;
        if (map_data.left_matches[a - 1] > 1 &&
        map_data.left_matches[a - 1] <= map_data.max)
            b = map_data.left_matches[a - 1] - 1;
        else {
            b = rand();
            b %= map_data.left_matches[a - 1] + 1;
        }
    }
    my_putstr("AI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", b, a);
    map_data = remove_match(map_data, a, b);
    return map_data;
}

int main(int ac, char **av)
{
    struct match map_data;
    int winning = 0;

    map_data.columns = 1;
    map_data.lines = 0;
    if (ac != 3)
        return 84;
    map_data.lines = my_getnbr(av[1]);
    map_data.max = my_getnbr(av[2]);
    if (map_data.lines < 1 || map_data.lines >= 100 || map_data.max <= 0)
        return 84;
    for (int a = 0; a != map_data.lines - 1; a++)
        map_data.columns = map_data.columns + 2;
    map_data = map_fill(map_data);
    map_draw(map_data);
    winning = matchstick(map_data);
    return winning;
}