/*
** EPITECH PROJECT, 2020
** ss
** File description:
** s
*/

#include "minishell.h"

int is_alpha_tab(char c)
{
    if (c != ' ' && c != '\t')
        return (1);
    return (0);
}

void copy2(char *tabstr, char *str, int pos, int end)
{
    int i = 0;

    for (; pos <= end; i++, pos++)
        tabstr[i] = str[pos];
    tabstr[i] = '\0';
}

int words2(char *str)
{
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha_tab(str[i]) == 0
        && is_alpha_tab(str[i + 1]) == 1 && is_alpha_tab(str[i - 1]) == 1)
            word += 1;
        if (str[i + 1] == '\0')
            word += 1;
    }
    return (word);
}

char **my_str_to_wordtab(char *str)
{
    char **temptab = malloc(sizeof(char *) * words2(str) + 1);
    int i = 0;
    int pos = 0;
    for (int x = 0; x < words2(str); x++, i++) {
        for (;str[i] && is_alpha_tab(str[i]) == 0; i++);
        pos = i;
        for (;str[i] && is_alpha_tab(str[i]) == 1; i++);
        temptab[x] = malloc(sizeof(char) * ((i - 1) - pos + 2));
        copy2(temptab[x], str, pos, i - 1);
    }
    return (temptab);
}