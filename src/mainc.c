/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    int sigout = 0;

    sigout = init_shell(ac, av, env);
    return (sigout);
}