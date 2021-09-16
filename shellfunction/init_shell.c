/*
** EPITECH PROJECT, 2020
** init_shell
** File description:
** init_shell
*/

#include "minishell.h"

void handler(int sig)
{
    if (sig == SIGINT && getpid() == mysh.sig) {
        write_text("\n");
        display_prompt(pt);
    }
}

void exit_test(void)
{
    if (strcompare_cd("exit\n", envs.linewn[0], 0, 5) == 1) {
        write_text("exit\n");
        exit(mysh.states);
    }
}

void testshell(prompt_t prompt, char ** env)
{
    envs.line = my_str_to_wordtab(strcp2(envs.buffer));
    envs.linewn = my_str_to_wordtab(envs.buffer);
    exit_test();
    mysh.cdsig = my_cd(prompt);
    mysh.evsig = my_env();
    if (mysh.cdsig != 1 && mysh.evsig != 1)
        mysh.lssig = my_ls();
    if (charintostr('/') == 1)
        mysh.execsig = my_exec();
    mysh.envsig = testenv();
    if (mysh.cdsig == 0 && mysh.lssig == 0
    && mysh.execsig == 0 && mysh.envsig == 0
    && mysh.execsig == 0 && mysh.evsig == 0)
        error_desc();
    refreshenv(env);
}

void shell(char ** env)
{
    prompt_t prompt;

    while (envs.getsignal != -1) {
        signal(SIGINT, handler);
        signal(SIGSEGV, handler);
        prompt = search_env();
        pt = prompt;
        display_prompt(prompt);
        envs.buffer = NULL;
        envs.getsignal = getline(&envs.buffer, &envs.bufsize, stdin);
        if (envs.getsignal == -1) {
            write_text("exit\n");
            exit(mysh.states);
        } else if (envs.getsignal > 1) {
            mysh.states = 0;
            testshell(prompt, env);
        }
    }
}

int init_shell(int ac, char **av, char ** env)
{
    if (*env != NULL)
        mysh.env = env;
    mysh.av = av;
    mysh.ac = ac;
    envs.bufsize = 512;
    envs.buffer = malloc(sizeof(char) * envs.bufsize);

    shell(env);
    return (1);
}