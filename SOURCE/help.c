/*
** EPITECH PROJECT, 2023
** -h option
** File description:
** ..
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

void display_help(void)
{
    my_putstr("Welcome to My Hunter!\n\n");
    my_putstr("Usage: my_hunter [options]\n");
    my_putstr("\nOptions:\n");
    my_putstr("-h   Display this help message.\n");
    my_putstr("     Right-click to shoot.\n");
    my_putstr("     Press the window's close button to exit.\n\n");
    my_putstr("Music by Diégo P-G\n");
}
