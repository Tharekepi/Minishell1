/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** main.c
*/

#include "my.h"

void my_signal(int sign)
{
    char *prompt;
    if (sign == SIGINT) {
        prompt = get_prompt();
        if (isatty(0))
            my_putstr("$> ");
    }
}

void detect_signal_child(int pid)
{
    if (WIFSIGNALED(pid)) {
        my_putstr(strsignal(WTERMSIG(pid)));
    }
}

char *get_prompt(void)
{
    char *buf, *prompt;
    int	i = 0;
    if (((buf = malloc(sizeof(char) * 4096)) == NULL)
        || (buf = getcwd(buf, 4096)) == NULL
        || (prompt = malloc(sizeof(char) * 4096)) == NULL)
        return (NULL);
    while (buf[i] != 0) {
        prompt[i] = buf[i];
        i++;
    }
    prompt[i] = 0;
    return (prompt);
}

int init_minishell(int ac, char **av, char **env, int ty)
{
    char *enter, *prompt, **arr;
    int	pid;
    signal(SIGINT, my_signal);
    while (1) {
        prompt = get_prompt();
        dol_prompt(prompt);
        if ((enter = get_next_line(0)) == NULL)
            break;
        if (my_strcmp(enter, "exit") == 0)
            break;
        arr = my_str_to_wordtab(enter);
        if (my_strcmp(arr[0], "cd") == 0)
            mcd(arr, env);
        else {
            pid = exec(arr, env);
            wait(&pid);
            detect_signal_child(pid);
        }
    }
    my_putstr("exit\n"); free(enter); return (0);
}

int	main(int ac, char **av, char **env)
{
    if (env == NULL)
        return (84);
    return (init_minishell(ac, av, env,isatty));
}
