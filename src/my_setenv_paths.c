/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** my_setenv.c
*/

#include "my.h"

char *c_env(char *var, char *value)
{
    int	i = 0, j;
    while (var[i] != '=' && var[i] != 0)
        i++;
    i++;
    if (value == NULL)
        var[i] = 0;
    else {
        j = 0;
        while (value[j] != 0)
        var[i++] = value[j++];
        var[i] = 0;
        }
    return (var);
}

char **setenv(char **ar, char **env)
{
    int	i = 0;
    if (ar[i] == NULL)
        return (env);
    while (env[i] != NULL && my_strncmp(env[i], ar[1], my_strlen(ar[1])) != 0)
    i++;
    if (env[i] == NULL) {
        env[i] = my_strcat(ar[1], "=");
        if (ar[2] == NULL)
            return (env);
        env[i] = my_strcat(env[i], ar[2]);
        env[i + 1] = NULL;
        return (env);
    }
    env[i] = c_env(env[i], ar[2]);
    return (env);
}

char **m_paths(char *str)
{
    char  **ar;
    int   i_str = 5, x, y = 0,l;
    if ((l = my_strlen(str)) == -1)
        return (NULL);
    if ((ar = malloc(sizeof(char *) * l)) == NULL)
        return (NULL);
    while (str[i_str] != 0) {
        if ((ar[y] = malloc(sizeof(char) * l)) == NULL)
            return (NULL);
        while ((str[i_str] != 0) && (str[i_str] == ':'))
            i_str++;
        x = 0;
        while (str[i_str] != 0 && str[i_str] != ':')
            ar[y][x++] = str[i_str++];
        ar[y][x++] = '/';
        ar[y++][x] = 0;
        while ((str[i_str] != 0) && (str[i_str] == ':'))
            i_str++;
        }
    ar[y] = NULL; return (ar);
}

char **to_path(char **env)
{
    int	i = 0;
    char **ar;
    while (env[i] != NULL && my_strncmp(env[i], "PATH=", 5) != 0)
        i++;
    if (env[i] == NULL)
        return (NULL);
    ar = m_paths(env[i]);
    return (ar);
}
