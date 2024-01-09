/*
** EPITECH PROJECT, 2023
** my hunter
** File description:
** ..
*/

#include "my.h"

int help_option(int argc, char **argv)
{
    if (argc != 1 && argc != 2)
        return 84;
    if (argc == 1)
        return 0;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && my_strlen(argv[1]) == 2) {
        display_help();
        return 0;
    }
    return 84;
}

int main(int argc, char **argv)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    char *path = "./artistic/music/game_music2.ogg";
    sfMusic *music = sfMusic_createFromFile(path);
    char *n = "My_Hunter";

    if (help_option(argc, argv) == 84)
        return 84;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    window = sfRenderWindow_create(video_mode, n, sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_loop(window);
    sfMusic_destroy(music);
    return 0;
}

int game_loop(sfRenderWindow *window)
{
    int go = 0;
    life score;

    score.score = 0;
    go = display_menu(window);
    if (go == 1)
        display_game(window);
    if (go == 2) {
        display_score(window, score);
        game_loop(window);
    }
}
