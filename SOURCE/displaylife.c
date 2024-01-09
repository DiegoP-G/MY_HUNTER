/*
** EPITECH PROJECT, 2023
** life gestion
** File description:
** ..
*/

#include "my.h"
#include "struct.h"

void display_cursor(sfRenderWindow *window, cursor my_cur)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(window);

    sfSprite_setPosition(my_cur.sprite, (sfVector2f){p.x -70.0, p.y - 100.0});
    sfRenderWindow_drawSprite(window, my_cur.sprite, NULL);
}

int display_life(sfRenderWindow *window, life *life, int i)
{
    char *number;

    if (i == 0)
        life->life = 3;
    if (life->life == 3)
        sfSprite_setTexture(life->sprite, life->texture3, sfFalse);
    if (life->life == 2)
        sfSprite_setTexture(life->sprite, life->texture2, sfFalse);
    if (life->life == 1)
        sfSprite_setTexture(life->sprite, life->texture1, sfFalse);
    if (life->life == 0)
        sfSprite_setTexture(life->sprite, life->texture0, sfFalse);
    number = int_to_string(life->score);
    sfText_setString(life->text, number);
    sfRenderWindow_drawText(window, life->text, NULL);
    sfRenderWindow_drawSprite(window, life->sprite, NULL);
    free(number);
}
