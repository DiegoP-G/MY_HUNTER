/*
** EPITECH PROJECT, 2023
** test
** File description:
** ->->
*/

#include "my.h"
#include "struct.h"

cursor init_cursor(void)
{
    cursor my_cursor;
    char *path = "./artistic/cursor2.png";

    my_cursor.cursor_texture = sfTexture_createFromFile(path, NULL);
    my_cursor.sprite = sfSprite_create();
    sfSprite_setTexture(my_cursor.sprite, my_cursor.cursor_texture, sfFalse);
    return my_cursor;
}

font_level init_level(void)
{
    font_level my_level;

    my_level.font = sfFont_createFromFile("./artistic/SuperMario256.ttf");
    my_level.text = sfText_create();
    sfText_setPosition(my_level.text, (sfVector2f){850.0, 440.0});
    sfText_setCharacterSize(my_level.text, 150);
    sfText_setFont(my_level.text, my_level.font);
    sfText_setFillColor(my_level.text, sfBlack);
    return my_level;
}

back_ground init_background(void)
{
    back_ground bg;

    bg.texture = sfTexture_createFromFile("./artistic/background.png", NULL);
    bg.sprite = sfSprite_create();
    sfSprite_setTexture(bg.sprite, bg.texture, sfFalse);
    return bg;
}

back_ground init_menu(void)
{
    back_ground menu;

    menu.texture = sfTexture_createFromFile("./artistic/MENU.png", NULL);
    menu.sprite = sfSprite_create();
    sfSprite_setTexture(menu.sprite, menu.texture, sfFalse);
    return menu;
}

life init_life(int nb)
{
    life vie;

    vie.life = nb;
    vie.score = 0;
    vie.texture3 = sfTexture_createFromFile("./artistic/vie/3vie.png", NULL);
    vie.texture2 = sfTexture_createFromFile("./artistic/vie/2vie.png", NULL);
    vie.texture1 = sfTexture_createFromFile("./artistic/vie/1vie.png", NULL);
    vie.texture0 = sfTexture_createFromFile("./artistic/vie/0vie.png", NULL);
    vie.position.x = 1600;
    vie.position.y = 8;
    vie.sprite = sfSprite_create();
    vie.font = sfFont_createFromFile("./artistic/SuperMario256.ttf");
    vie.text = sfText_create();
    sfText_setPosition(vie.text, (sfVector2f){20, 8});
    sfText_setCharacterSize(vie.text, 60);
    sfText_setFont(vie.text, vie.font);
    sfText_setFillColor(vie.text, sfBlack);
    sfSprite_setPosition(vie.sprite, vie.position);
    return vie;
}
