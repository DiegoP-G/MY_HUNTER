/*
** EPITECH PROJECT, 2023
** my h
** File description:
** MY_H
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <time.h>
    #include "struct.h"
    #include <SFML/System/Export.h>
    #include <SFML/Graphics/Font.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Audio/Music.h>
void display_help(void);
char **write_score_in_file(int i);
char *my_strcpy(char *dest , char const *src);
char **put_in_array(int i, char *buff);
char **sort_score(int l, char **env);
int my_getnbr(char const *src);
char *my_strdup(char const *src);
char **malloc_score(void);
void display_score(sfRenderWindow *window, life score_struct);
int lenth_array(char **score);
int my_strlen(char const *str);
sfTexture *create_bird_texture(void);
cursor init_cursor(void);
font_level init_level(void);
void free_bird(bird **head, bird *prev, bird *current);
int display_menu(sfRenderWindow *window);
back_ground init_menu(void);
void display_birds(sfRenderWindow *window, bird *current);
int display_life(sfRenderWindow *window, life *life, int i);
void display_cursor(sfRenderWindow *window, cursor my_cur);
void print_level(int i, int nb, sfRenderWindow *window, font_level my_level);
int how_many_digits(int nb);
void event(sfRenderWindow *window, bird **current, life *life);
char *int_to_string(int nb);
life init_life(int nb);
back_ground init_background(void);
int creat_bird(int i, bird **canard_list, sfClock *clock, int *level);
bird *create_bird(int *level);
void my_put_in_list(bird **canardList, int *level);
void clock_canard(sfRenderWindow *window, sfClock *clock, bird *canard);
void display_game(sfRenderWindow *window);
int game_loop(sfRenderWindow *window);
void play_music(void);
void shoot_sound(sfRenderWindow *window, sfEvent event);


#endif /* !MY_H_ */
