/*
** EPITECH PROJECT, 2020
** display
** File description:
** display prompt
*/

#include "minishell.h"

prompt_t searchenv_test(prompt_t prompt)
{
    for (int i = 0; mysh.env[i] != NULL; i++)
        if (strcompare_path("PATH", mysh.env[i]) == 1)
            prompt.path = mysh.env[i];
    for (int i = 0; mysh.env[i] != NULL; i++)
        if (strcompare_path("USER", mysh.env[i]) == 1)
            prompt.session = strcut(mysh.env[i], 5);
    for (int i = 0; mysh.env[i] != NULL; i++)
        if (strcompare_path("PWD", mysh.env[i]) == 1)
            prompt.pwd = strcut(mysh.env[i], 4);
    for (int i = 0; mysh.env[i] != NULL; i++)
        if (strcompare_path("HOME", mysh.env[i]) == 1)
            prompt.home = strcut(mysh.env[i], 5);
    return (prompt);
}

char *strcut2(char *str, int x, int y)
{
    char *tmp = malloc(sizeof(char) * y + 2);
    int len = 0;
    int i = x;

    for (; i <= y; i++, len++)
        tmp[len] = str[i];
    tmp[len] = '\0';
    return (tmp);
}

char *strcut(char *str, int x)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    int len = 0;
    int i = x;

    for (; i <= my_strlen(str); i++, len++)
        tmp[len] = str[i];
    return (tmp);
}

int strcompare_path(char *str_base, char *str_test)
{
    for (int pt = 0; str_base[pt] != 0; pt++) {
        if (str_test[pt] != str_base[pt])
            return (0);
    }
    return (1);
}

void display_prompt(prompt_t prompt)
{
    char *str = NULL;

    str = getcwd(NULL, 0);
    write_text("[");
    write_text(prompt.session);
    write_text(":~");
    write_text(pwdcut(str));
    write_text("]");
    write_text("$ ");
}