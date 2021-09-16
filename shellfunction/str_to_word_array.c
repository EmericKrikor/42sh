/*
** EPITECH PROJECT, 2020
** ss
** File description:
** s
*/

#include "minishell.h"

int is_alpha(char c)
{
    if (c != ':' && c != ' ')
        return (1);
    return (0);
}

void copy(char *tabstr, char *str, int pos, int end)
{
    int i = 0;

    for (; pos <= end; i++, pos++)
        tabstr[i] = str[pos];
    tabstr[i] = '\0';
}

int words(char *str)
{
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0
        && is_alpha(str[i + 1]) == 1 && is_alpha(str[i - 1]) == 1)
            word += 1;
        if (str[i + 1] == '\0')
            word += 1;
    }
    return (word);
}

char **my_strtwa(char *str)
{
    char **temptab = malloc(sizeof(char *) * words(str) + 1);
    int i = 0;
    int pos = 0;

    for (int x = 0; x < words(str); x++, i++) {
        for (;str[i] && is_alpha(str[i]) == 0; i++);
        pos = i;
        for (;str[i] && is_alpha(str[i]) == 1; i++);
        temptab[x] = malloc(sizeof(char) * ((i - 1) - pos + 2));
        copy(temptab[x], str, pos, i - 1);
    }
    return (temptab);
}