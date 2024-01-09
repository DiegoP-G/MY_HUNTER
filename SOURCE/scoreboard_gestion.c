/*
** EPITECH PROJECT, 2023
** score board getion
** File description:
** ..
*/

#include "my.h"

int event_for_score_board(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            return 1;
        }
    }
    return 0;
}

back_ground init_leader_board(void)
{
    back_ground menu;
    char *path = "./artistic/leader_board.png";

    menu.texture = sfTexture_createFromFile(path, NULL);
    menu.sprite = sfSprite_create();
    sfSprite_setTexture(menu.sprite, menu.texture, sfFalse);
    return menu;
}

score_board init_score(void)
{
    score_board my_level;

    my_level.font = sfFont_createFromFile("./artistic/SuperMario256.ttf");
    my_level.text = sfText_create();
    sfText_setCharacterSize(my_level.text, 50);
    sfText_setFont(my_level.text, my_level.font);
    sfText_setFillColor(my_level.text, sfBlack);
    return my_level;
}

void display_stwo(sfRenderWindow *window, score_board my_score, char **score)
{
    int lenth = lenth_array(score);
    int i = 0;
    sfVector2f position;

    position.x = 960.0;
    position.y = 137.0;
    while (i < 7 && i < lenth) {
        sfText_setPosition(my_score.text, position);
        sfText_setString(my_score.text, score[lenth - i]);
        sfRenderWindow_drawText(window, my_score.text, NULL);
        position.y += 110.0;
        i++;
    }
}

void display_score(sfRenderWindow *window, life score_struct)
{
    char **score;
    score_board font_score = init_score();
    back_ground bg = init_leader_board();

    score = write_score_in_file(score_struct.score);
    while (event_for_score_board(window) == 0
    && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg.sprite, NULL);
        display_stwo(window, font_score, score);
    }
}
