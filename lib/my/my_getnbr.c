/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Get a number from a string
*/

int my_getnbr(char const *str)
{
    int number = 0;
    int a = 0;

    for (; '0' <= str[a] && str[a] <= '9' && str[a] != '\0'; a++) {
        number *= 10;
        number += str[a] - '0';
    }
    return (number);
}
