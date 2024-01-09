/*
** EPITECH PROJECT, 2023
** music for my hunter
** File description:
** ..
*/
#include "my.h"


void shoot_sound(sfRenderWindow *window, sfEvent event)
{
    sfMusic *shoot_sound;
    sfMusic *bullet_of;

    shoot_sound = sfMusic_createFromFile("./artistic/music/shoot_sound.wav");
    bullet_of = sfMusic_createFromFile("./artistic/music/get_of_bullet.wav");
    if (event.mouseButton.button == sfMouseLeft) {
        sfMusic_setVolume(shoot_sound, 35.0);
        sfMusic_setVolume(bullet_of, 15.0);
        sfMusic_play(shoot_sound);
        sfMusic_play(bullet_of);
    }
}
