/*
** EPITECH PROJECT, 2023
** GET NBR
** File description:
** ..
*/
#include "../my.h"

int powerten_two(char const *src, int c)
{
    int i = 0;

    while (src[i] != 0 && src[i] <= '9' && src[i] >= '0') {
        if ( src[i] <= '9' && src[i] >= '0')
            c = c * 10;
        if (c != 1 && (src[i] > '9' || src[i] < '0')) {
            break;
        }
        i++;
    }
    return (c / 10);
}

int havenbr_two(char const *src, int nbr, int c)
{
    int a = 0;
    int i = 0;

    while (src[i] != 0 && src[i] <= '9' && src[i] >= '0') {
        if (src[i] <= '9' && src[i] >= '0' && a == 0) {
            nbr = nbr + (src[i] - 48) * c;
            c = c / 10;
        }
        if (src[i] > '9' || src[i] < '0')
            a = 1;
        i++;
    }
    return nbr;
}

int my_getnbr(char const *src)
{
    int i = 0;
    int nbr = 0;
    int c = 1;
    int m = 0;
    int a = 0;

    c = powerten_two(src, c);
    nbr = havenbr_two(src, nbr, c);
    return (nbr);
}
