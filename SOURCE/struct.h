/*
** EPITECH PROJECT, 2023
** my h
** File description:
** MY_H
*/

#ifndef MY_STRUCT
    #define MY_STRUCT
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <time.h>
typedef struct cursor_struct{
    sfTexture *cursor_texture;
    sfSprite *sprite;
}cursor;
typedef struct score_board {
    char *number;
    sfFont *font;
    sfText *text;
}score_board;

typedef struct font_level {
    char *number;
    sfFont *font;
    sfText *text;
}font_level;

typedef struct life {
    sfTexture *texture1;
    sfTexture *texture2;
    sfTexture *texture3;
    sfTexture *texture0;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f score_position;
    sfFont* font;
    sfText* text;
    int life;
    int score;
}life;

typedef struct back_ground {
    sfTexture *texture;
    sfSprite *sprite;
    sfVideoMode VideoMode;
}back_ground;

typedef struct i_bird {
    int dead;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    float velocity;
    struct i_bird *next;
}bird;



#endif
