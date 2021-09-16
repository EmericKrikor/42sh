/*
** EPITECH PROJECT, 2019
** write error
** File description:
** write error for projetc
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++);
    return (nb);
}

char *strcp2(char *str)
{
    char *cpy = NULL;
    int pt = 0;

    cpy = malloc(sizeof(char) * my_strlen(str));
    for (; str[pt] != '\n'; pt++)
        cpy[pt] = str[pt];
    cpy[pt] = '\0';
    return (cpy);
}

char *strcp(char *str)
{
    char *cpy = NULL;
    int pt = 0;

    cpy = malloc(sizeof(char) * my_strlen(str));
    for (; str[pt] != '\n' && str[pt] != '\0'; pt++) {
        if (str[pt] == ' ')
            break;
        cpy[pt] = str[pt];
    }
    cpy[pt] = '\0';
    return (cpy);
}

void write_error(char *s)
{
    write(2, s, my_strlen(s));
}

void write_text(char *s)
{
    write(1, s, my_strlen(s));
}
