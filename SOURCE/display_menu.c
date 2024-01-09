/*
** EPITECH PROJECT, 2023
** display menu game
** File description:
** ..
*/
#include "my.h"
#include "struct.h"
int event_for_menu(sfRenderWindow *window)
{
    sfEvent event;
    int i = 0;
    sfVector2i click;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            click = sfMouse_getPositionRenderWindow(window);
        }
        if (click.x > 835 && click.x < 1050 && click.y > 500 && click.y < 620)
            i = 1;
        if (click.x > 715 && click.x < 1185 && click.y > 710 && click.y < 832)
            i = 2;
    }
    return i;
}

char **write_score_in_file(int i)
{
    int fd = open("./score.txt", O_APPEND | O_WRONLY | O_CREAT);
    char *buff;

    write(fd, int_to_string(i), my_strlen(int_to_string(i)));
    write(fd, "\n", 1);
    close(fd);
    return malloc_score();
}

char **put_in_array(int i, char *buff)
{
    int b = 0;
    int c = 0;
    char **score = malloc(sizeof(char *) * (i));

    while (b < i - 1) {
        if (c == 0) {
            score[b] = my_strdup(int_to_string(my_getnbr(buff)));
            b++;
        }
        if (buff[c] == '\n') {
            score[b] = my_strdup(int_to_string(my_getnbr(buff + c + 1)));
            b++;
        }
        c++;
    }
    score[b] = NULL;
    sort_score(b, score);
    return score;
}

char **malloc_score(void)
{
    int fd = open("./score.txt", O_RDONLY);
    char buff[8000];
    int i = 0;
    int c = 0;

    read(fd, buff, 8000);
    while (buff[c] != '\0') {
        if (buff[c] == '\n')
            i++;
        c++;
    }
    return put_in_array(i, buff);
}

int display_menu(sfRenderWindow *window)
{
    back_ground bg = init_menu();
    int stay = 0;

    while (stay == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        stay = event_for_menu(window);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg.sprite, NULL);
    }
    return stay;
}
