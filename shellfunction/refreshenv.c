/*
** EPITECH PROJECT, 2020
** refreshenv
** File description:
** refreshenv
*/

#include "minishell.h"

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}

int my_env(void)
{
    if (mysh.env != NULL) {
        if (strcompare_cd("env\n", envs.linewn[0], 0, 4) == 1) {
            for (int i = 0; mysh.env[i] != NULL; i++) {
                write_text(mysh.env[i]);
                write_text("\n");
            }
            return (1);
        }
    }
    return (0);
}

int testenv(void)
{
    if (strcompare_cd("setenv", envs.line[0], 0, 7) == 1) {
        mysh.env = my_setenv(mysh.env, my_str_to_wordtab(strcp2(envs.buffer)));
        return (1);
    } if (strcompare_cd("unsetenv", envs.linewn[0], 0, 9) == 1) {
        char **temp = my_str_to_wordtab(strcp2(envs.buffer));
        mysh.env = my_unsetenv(mysh.env, temp[1]);
        return (1);
    }

    return (0);
}

char *alloc_str(char **tab)
{
    char *str = NULL;
    int i = 0;
    int j = 0;

    if ((str = malloc((my_strlen(tab[1]) + 2) * sizeof(char *))) == NULL)
        return (NULL);
    while (tab[1][i] != '\0')
        str[j++] = tab[1][i++];
    str[j++] = '=';
    str[j++] = '\0';
    return str;
}

void refreshenv(char **env)
{
    if (envs.envpwd != NULL && envs.oldenvpwd != NULL && mysh.env != NULL) {
        for (int i = 0; mysh.env[i] != NULL; i++)
            if (strcompare_path("OLDPWD", mysh.env[i]) == 1) {
                env[i] = strcut2(env[i], 0, 6);
                env[i] = my_strcat(env[i],
                strcut2(envs.oldenvpwd, 1, my_strlen(envs.oldenvpwd)));
            }
        for (int i = 0; mysh.env[i] != NULL; i++)
            if (strcompare_path("PWD", mysh.env[i]) == 1) {
                env[i] = strcut2(env[i], 0, 3);
                env[i] = my_strcat(env[i],
                strcut2(envs.envpwd, 1, my_strlen(envs.envpwd)));
            }
    }
}