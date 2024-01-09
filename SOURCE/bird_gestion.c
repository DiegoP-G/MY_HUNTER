/*
** EPITECH PROJECT, 2023
** bird gestion..
** File description:
** ..
*/

#include "my.h"
#include "struct.h"

void my_put_in_list(bird **canardList, int *level)
{
    bird *newBird = create_bird(&*level);
    bird *current = *canardList;

    newBird->next = NULL;
    if (*canardList == NULL) {
        *canardList = newBird;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBird;
    }
}

void display_birds(sfRenderWindow *window, bird* current)
{
    while (current != NULL) {
        clock_canard(window, current->clock, current);
        sfRenderWindow_drawSprite(window, current->sprite, NULL);
        current = current->next;
    }
}

void clock_canard(sfRenderWindow *window, sfClock *clock, bird *canard)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;
    int rond = rand() % 2;
    float speed = canard->velocity;

    if (speed * seconds > 4) {
        if (canard->rect.left != 990) {
            canard->rect.left += 198;
        } else
            canard->rect.left = 0;
        if (rond == 1 && canard->position.y > 100)
            canard->position.y -= rand() % 20;
        if (rond != 1 && canard->position.y < 900)
            canard->position.y += rand() % 20;
        canard->position.x += canard->velocity;
        sfSprite_setPosition(canard->sprite, canard->position);
        sfSprite_setTextureRect(canard->sprite, canard->rect);
        sfClock_restart(clock);
    }
}

int creat_bird(int i, bird **canard_list, sfClock *clock, int *level)
{
    float seconds;
    sfTime time;
    int rd = (rand() % 30);

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (i == -1 && seconds > 3)
        i++;
    if (i <= 15 && i != -1 && seconds > 0.1 + rd) {
        my_put_in_list(canard_list, level);
        i++;
        sfClock_restart(clock);
    }
    if (i == 16 && *canard_list == NULL) {
        i = -1;
        *level = *level + 1;
    }
    return i;
}
