/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** my_cdexec.c
*/

#include "my.h"

char *find_environment_variable_value(char *str, char **env)
{
    char *dest;
    int i_dest = 0, y = 0, x = 0;
    if ((dest = malloc(sizeof(char) * 4096)) == NULL) {
        return NULL;
    }

    while (env[y] != NULL && my_strncmp(env[y], str, my_strlen(str)) != 0) {
        y++;
    }

    if (env[y] == NULL) {
        return NULL;
    }

    x = my_strlen(str);
    while (env[y][x] != 0) {
        dest[i_dest++] = env[y][x++];
    }
    dest[i_dest] = 0;
    return dest;
}

int	mcd(char **arr, char **env)
{
    char *dest, *buffer, **tab;
    if ((buffer = malloc(sizeof(char) * 4096)) == NULL)
        return (-1);
    if ((tab = malloc(sizeof(char *) * 4096)) == NULL)
        return (-1);
    tab[0] = "setenv";
    tab[1] = "OLDPWD=";
    tab[2] = get_prompt();
    tab[3] = NULL;
    if (arr[1] == NULL || my_strcmp(arr[1], "~") == 0)
        dest = find_environment_variable_value("HOME=", env);
    else if (my_strcmp(arr[1], "-") == 0)
        dest = find_environment_variable_value("OLDPWD=", env);
    else
        dest = arr[1];
    setenv(tab, env);
    dest_null(dest);
    chdir_dest(dest);
    return (-1);
}

int	exec(char **arr, char **env)
{
    char **paths, *binary;
    int	i = 0, pid = fork();
    if ((paths = to_path(env)) == NULL)
        return (-1);
    while (paths[i]) {
        binary = my_strcat(paths[i], arr[0]);
        if (pid == 0) {
            c_execve(arr,env,binary);
            } else
                return (-1);
        i++;
    }
    my_putstr(arr[0]);
    my_putstr(": Command not found.\n");
    exit(0);
}
