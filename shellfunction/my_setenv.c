/*
** EPITECH PROJECT, 2020
** setenv /unsetenv
** File description:
** setenv/unsetenv
*/

#include "minishell.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i <= n) {
        if (s1[i] == s2[i])
            i = i + 1;
        else {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}

char **my_realloc(char **tab)
{
    int i = 0;
    char **tmp;

    if ((tmp = malloc((my_tablen(tab) + 2) * sizeof(*tmp))) == NULL)
        return (NULL);
    for (; tab[i] != NULL; i++)
        tmp[i] = tab[i];
    tmp[i] = NULL;
    return (tmp);
}

char *attribution(char **tab)
{
    char *str = NULL;
    int i = 0;
    int j = 0;

    if (tab[2] != NULL) {
        if ((str = malloc((my_strlen(tab[1]) +
        my_strlen(tab[2]) + 2) * sizeof(char *))) == NULL)
            return (NULL);
        while (tab[1][i] != '\0')
            str[j++] = tab[1][i++];
        str[j++] = '=';
        i = 0;
        while (tab[2][i])
            str[j++] = tab[2][i++];
        str[j] = '\0';
        return (str);
    } else {
        str = alloc_str(tab);
        return (str);
    }
}

char **my_setenv(char **env, char **tab)
{
    if (tab[1] == NULL)
        return (env);
    if (env == NULL)
        env = malloc(sizeof(char *) * 1 + 1);
    if (check_alpha(tab) == 1)
        return (env);
    else
        return (testsetenv(env, tab));
}

char **my_unsetenv(char **env, char *str)
{
    char **dest;
    int j = 0;
    int k = 0;

    if (env != NULL) {
        if ((dest = malloc((my_tablen(env) + 1) * sizeof(*dest))) == NULL)
            return (NULL);
        while (env[j] != NULL) {
            if (my_strncmp(env[j], str, my_strlen(str) - 1) == 0 &&
            env[j][my_strlen(str)] == '=')
                j++;
            else
                dest[k++] = env[j++];
        }
        dest[k] = NULL;
        return (dest);
    } else
        return (NULL);
}