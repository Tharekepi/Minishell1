/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** my_function.c
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    char c = str[i];

    while (c != '\0') {
        my_putchar(c);
        i++;
        c = str[i];
    }
    return 0;
}
