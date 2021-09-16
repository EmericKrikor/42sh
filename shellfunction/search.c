/*
** EPITECH PROJECT, 2020
** search
** File description:
** search
*/

#include "minishell.h"

char *pwdcut(char *str)
{
    int x = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            x++;
        if (x == 3) {
            str = strcut(str, i);
            break;
        }
    }
    return (str);
}

void error_desc(void)
{
    write_error(mysh.buff[0]);
    write_error(": Command not found.\n");
}

int charintostr(char c)
{
    for (int i = 0; envs.line[0][i] != '\0'; i++)
        if (envs.line[0][i] == c)
            return (1);
    return (0);
}

int my_ls(void)
{
    int statue;
    mysh.buff = my_str_to_wordtab(strcp2(envs.buffer));
    char *ls = parth_path(mysh.buff[0]);

    if (ls != NULL) {
        mysh.proces = fork();
        wait(&statue);
        if (mysh.proces == -1)
            exit (84);
        if (mysh.proces == 0) {
            if (execve(ls, mysh.buff, mysh.env) == -1)
                exit(EXIT_FAILURE);
            exit(EXIT_SUCCESS);
        }
        return (1);
    }
    return (0);
}

prompt_t search_env(void)
{
    prompt_t prompt = {0};

    if (mysh.env != NULL && mysh.env[0] != NULL) {
        prompt = searchenv_test(prompt);
        if (prompt.session == NULL)
            prompt.session = strcut2(getcwd(NULL, 0), 6, 9);
        if (prompt.path != NULL)
            mysh.tabpath = my_strtwa(strcut(prompt.path, 5));
    } else
        prompt.session = strcut2(getcwd(NULL, 0), 6, 9);
    return (prompt);
}