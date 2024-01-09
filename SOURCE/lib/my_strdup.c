/*
** EPITECH PROJECT, 2023
** my strdup
** File description:
** Write a function that allocates memory and copies
** the string given as argument in it
*/
#include <stdlib.h>
#include "../my.h"

char *my_strdup(char const *src)
{
    char *send;

    send = malloc(sizeof(char) * my_strlen(src) + 1);
    send = my_strcpy(send, src);
    return send;
}
