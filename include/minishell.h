/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell
*/

#ifndef minishell
#define minishell

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pwd.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct env
{
    char **env;
    size_t bufsize;
    char * buffer;
    char **line;
    char **linewn;
    int getsignal;
    int signal;
    char *envpwd;
    char *oldenvpwd;
} env_t;

env_t envs;

typedef struct mysh
{
    char *path;
    char **tabpath;
    char *pwd;
    char **env;
    char **buff;
    char **av;
    pid_t proces;
    pid_t sig;
    int ac;
    int cdsig;
    int lssig;
    int execsig;
    int exitsig;
    int envsig;
    int evsig;
    int states;
    int sigexecv;
} mysh_t;

mysh_t mysh;

typedef struct prompt
{
    char *path;
    char *home;
    char *session;
    char *pwd;
}prompt_t;

prompt_t pt;

int init_shell(int ac, char **av, char ** env);
void handler(int sig);
int strcompare_path(char *str_base, char *str_test);
char **my_str_to_wordtab(char *str);
char *strcp(char *str);
int check_alpha(char **tab);
char **testsetenv(char **env, char **tab);
char *strcut(char *str, int x);
char *strcp2(char *str);
int my_strlen(char *str);
void write_text(char *s);
void display_prompt(prompt_t prompt);
char *attribution(char **tab);
char **my_realloc(char **tab);
int my_strncmp(char *s1, char *s2, int n);
int my_cd(prompt_t prompt);
int strcompare_cd(char *str_base, char *str_test, int x, int y);
void write_error(char *s);
char **my_setenv(char **env, char **my_tab);
char **my_unsetenv(char **env, char *str);
int testenv(void);
char *alloc_str(char **tab);
int my_env(void);
int my_tablen(char **tab);
char *parth_path(char * str);
char **my_strtwa(char *str);
char *my_strcat(char *dest, char *src);
void refreshenv(char **env);
char *strcut2(char *str, int x, int y);
int my_exec(void);
int charintostr(char c);
void error_desc(void);
char *pwdcut(char *str);
int my_ls(void);
prompt_t search_env(void);
prompt_t searchenv_test(prompt_t prompt);

#endif /* !minishell */