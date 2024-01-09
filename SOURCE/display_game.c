/*
** EPITECH PROJECT, 2023
** display bk
** File description:
** ..
*/
#include "my.h"
#include "struct.h"

void fail(bird *current, life *life)
{
    while (current != NULL) {
        if (current->position.x > 1920)
            life->life = 0;
        current = current->next;
    }
}

void formal_display(sfRenderWindow *w, back_ground bg, bird *cL, cursor my_c)
{
    sfRenderWindow_setMouseCursorVisible(w, sfFalse);
    sfRenderWindow_display(w);
    sfRenderWindow_clear(w, sfBlack);
    sfRenderWindow_drawSprite(w, bg.sprite, NULL);
    display_birds(w, cL);
    display_cursor(w, my_c);
}

void display_game(sfRenderWindow *window)
{
    back_ground bg = init_background();
    sfClock *spawn = sfClock_create();
    life life = init_life(3);
    bird *canardList = NULL;
    font_level mylevel = init_level();
    cursor my_cursor = init_cursor();
    int i = -1;
    int level = 0;

    while (sfRenderWindow_isOpen(window) && life.life != 0) {
        formal_display(window, bg, canardList, my_cursor);
        i = creat_bird(i, &canardList, spawn, &level);
        event(window, &canardList, &life);
        display_life(window, &life, i);
        print_level(i, level, window, mylevel);
        fail(canardList, &life);
    }
    sfClock_destroy(spawn);
    display_score(window, life);
    game_loop(window);
}
