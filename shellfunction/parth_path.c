/*
** EPITECH PROJECT, 2020
** parth path
** File description:
** parth path$
*/

#include "minishell.h"

char **testsetenv(char **env, char **tab)
{
    char *str = NULL;
    int b = 0;
    int j = 0;

    for (;env[j] != NULL; j++) {
        if (my_strncmp(env[j], tab[1], my_strlen(tab[1]) - 1) == 0
        && env[j][my_strlen(tab[1])] == '=') {
            b = 1;
            if ((str = attribution(tab)) != NULL)
                env[j] = str;
        }
    } if (b == 0 && (str = attribution(tab)) != NULL) {
        env = my_realloc(env);
        env[j++] = str;
        env[j] = NULL;
    }
    return (env);
}

int check_alpha(char **tab)
{
    for (int i = 0; tab[1][i] != '\0'; i++) {
        if (i == 0 && (tab[1][i] >= '0' && tab[1][i] <= '9')) {
            write_text(
            "setenv: Variable name must contain alphanumeric characters.\n");
            return (1);
        } else if (!(tab[1][i] >= '0' && tab[1][i] <= '9') &&
        !(tab[1][i] >= 'a' && tab[1][i] <= 'z') &&
        !(tab[1][i] >= 'A' && tab[1][i] <= 'Z')) {
            write_text(
            "setenv: Variable name must contain alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int x = 0;
    char *new;

    new = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 2);
    for (; dest[x] != '\0'; x++)
        new[x] = dest[x];
    new[x] = '/';
    x++;
    for (; i <= my_strlen(src); i++) {
        new[x] = src[i];
        x++;
    }
    return (new);
}

char *parth_path(char *str)
{
    char *tmp = NULL;

    if (mysh.tabpath != NULL) {
        for (int i = 0; mysh.tabpath[i] != NULL; i++) {
            tmp = my_strcat(mysh.tabpath[i], str);
            if (access(tmp, F_OK) == 0)
                return (tmp);
            free(tmp);
        }
    }
    return (NULL);
}