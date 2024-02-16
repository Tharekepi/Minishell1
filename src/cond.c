/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** cond.c
*/

#include "my.h"

int dol_prompt(char *prompt)
{
    if (isatty(0))
        my_putstr("$> ");
}

int chdir_dest(char *dest)
{
    if (chdir(dest) != -1)
        return (0);
    else {
        file_perm(dest);
    }
}

int dest_null(char *dest)
{
    if (dest == NULL)
        return (-1);
}

int file_perm(char *dest)
{
    if (access(dest, F_OK) == -1) {
        my_putstr(dest);
        my_putstr(" : No such file or directory.\n");
        } else if (access(dest, X_OK) == -1) {
            my_putstr(dest);
            my_putstr(": Permission denied.\n");
        }
}

int c_execve(char **arr, char **env, char *binary)
{
    if (my_strncmp(arr[0], "./", 2) == 0 || arr[0][0] == '/')
        execve(arr[0], arr, env);
    else
        execve(binary, arr, env);
}
