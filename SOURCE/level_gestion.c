/*
** EPITECH PROJECT, 2023
** level gestion
** File description:
** ..
*/

#include "my.h"
#include "struct.h"

void print_level(int i, int nb, sfRenderWindow *window, font_level my_level)
{
    char *number = int_to_string(nb + 1);

    sfText_setString(my_level.text, number);
    if (i == -1)
        sfRenderWindow_drawText(window, my_level.text, NULL);
    free(number);
}
