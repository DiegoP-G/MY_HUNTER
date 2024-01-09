/*
** EPITECH PROJECT, 2023
** init bird
** File description:
** ..
*/

#include "my.h"
#include "struct.h"

sfTexture *create_bird_texture(void)
{
    int rd = rand() % 3;
    sfTexture* texture = NULL;

    if (rd == 1)
        texture = sfTexture_createFromFile("./artistic/bird2.png", NULL);
    else if (rd == 2)
        texture = sfTexture_createFromFile("./artistic/birds/rouge.png", NULL);
    else
        texture = sfTexture_createFromFile("./artistic/birds/jaune.png", NULL);
    return texture;
}

bird *create_bird(int *level)
{
    bird *newBird = malloc(sizeof(bird));

    newBird->dead = 0;
    newBird->texture = create_bird_texture();
    newBird->sprite = sfSprite_create();
    newBird->rect.top = 0;
    newBird->rect.height = 135;
    newBird->rect.left = 0;
    newBird->velocity = 15 + rand() % 25 + (4 * (*level));
    newBird->rect.width = 200;
    newBird->position.x = 0.0;
    newBird->position.y = (rand() % 900) * 1.0 + 50;
    newBird->clock = sfClock_create();
    sfSprite_setPosition(newBird->sprite, newBird->position);
    sfSprite_setTextureRect(newBird->sprite, newBird->rect);
    sfSprite_setTexture(newBird->sprite, newBird->texture, sfFalse);
    return newBird;
}
