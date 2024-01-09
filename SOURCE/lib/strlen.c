/*
** EPITECH PROJECT, 2023
** strlen
** File description:
** ..
*/

#include "../my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char temp;

    while (i <= len / 2) {
        temp = str[len - i];
        str[len - i] = str[i];
        str[i] = temp;
        i++;
    }
    return (str);
}

int how_many_digits(int nb)
{
    int i = 0;

    while (nb >= 10) {
        nb = nb / 10;
        i++;
    }
    return i + 1;
}

char *int_to_string(int nb)
{
    int len = how_many_digits(nb);
    char *number = malloc(sizeof(char) * len + 1);
    int i = 0;
    int temp = nb;

    while (i < len) {
        number[i] = '0' + temp % 10;
        temp = temp / 10;
        i++;
    }
    number[i] = '\0';
    return my_revstr(number);
}
