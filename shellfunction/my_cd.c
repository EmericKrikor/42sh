/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "minishell.h"

int strcompare_cd(char *str_base, char *str_test, int x, int y)
{
    for (int pt = x; pt != y; pt++) {
        if (str_test[pt] != str_base[pt])
            return (0);
    }
    return (1);
}

int my_exec(void)
{
    int statue;
    char *buff = strcp2(envs.buffer);
    char *args[] = {buff, NULL};
    struct stat test;

    if (lstat(buff, &test) != -1) {
        mysh.proces = fork();
        if (mysh.proces == 0) {
            execve(args[0], args, mysh.env);
        } else {
            waitpid(mysh.proces, &statue, WUNTRACED | WCONTINUED);
            if (WTERMSIG(statue) == 11) {
                mysh.states = 139;
                write_error("Segmentation fault\n");
            }
        }
        return (1);
    }
    return (0);
}

int my_cd(prompt_t prompt)
{
    if (strcompare_cd("cd", envs.line[0], 0, 3) == 1) {
        if (strcompare_cd("cd\n", envs.linewn[0],
        0, my_strlen(envs.buffer)) == 1)
            chdir(prompt.home);
        else if (strcompare_cd("cd", envs.line[0], 0, 3) == 1) {
            if (chdir(strcp2(envs.linewn[1])) == -1) {
                write_error(strcp2(envs.linewn[1]));
                write_error(": Not a directory.\n");
                return (1);
            }
        }
        envs.envpwd = getcwd(NULL, 1000);
        return (1);
    }
    return (0);
}