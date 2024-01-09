/*
** EPITECH PROJECT, 2023
** my events for my hunter
** File description:
** ..
*/

#include "my.h"
#include "struct.h"

int touch(sfVector2f clickPosition, bird *canard)
{
    sfFloatRect allcoo = sfSprite_getGlobalBounds(canard->sprite);
    int i = sfFloatRect_contains(&allcoo, clickPosition.x, clickPosition.y);

    if (i == 1)
        return 1;
    return 0;
}

void free_bird(bird **head, bird *prev, bird *current)
{
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        *head = current->next;
    }
    sfTexture_destroy(current->texture);
    sfSprite_destroy(current->sprite);
    free(current);
}

void verification_if_dead(sfRenderWindow* window, bird **head, life* life)
{
    int i = 0;
    sfVector2i clickPosition = sfMouse_getPositionRenderWindow(window);
    bird *current = *head;
    bird *prev = NULL;

    while (current != NULL) {
        if (touch((sfVector2f){(float)clickPosition.x,
        (float)clickPosition.y}, current)) {
            i++;
            free_bird(head, prev, current);
        } else {
            prev = current;
        }
        current = current->next;
    }
    if (i == 0 && life->life > 0 && *head != NULL) {
        life->life -= 1;
    } else
        life->score += i * 100;
}

void event(sfRenderWindow *window, bird **current, life *life)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            shoot_sound(window, event);
            verification_if_dead(window, current, life);
        }
    }
}
