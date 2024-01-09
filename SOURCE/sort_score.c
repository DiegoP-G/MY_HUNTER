/*
** EPITECH PROJECT, 2023
** sort the score
** File description:
** ..
*/

#include "my.h"


char **reprint_score(int l, char **env)
{
    char *dest;

    for (int a = 1; a < l; a++) {
        if (my_getnbr(env[a - 1]) > my_getnbr(env[a])) {
                dest = env[a - 1];
                env[a - 1] = env[a];
                env[a] = dest;
            }
    }
    return env;
}

char **sort_score(int l, char **env)
{
    int c = 0;

    while (c < l) {
        env = reprint_score(l, env);
        c++;
    }
    return env;
}
