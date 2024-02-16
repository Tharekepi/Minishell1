/*
** EPITECH PROJECT, 2022
** Minishell1
** File description:
** my.h
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#ifndef	MY_H_
    #define	MY_H_

    #define	READ_SIZE (1)
    #define	SIZE_MALLOC (4096)
    typedef struct s_vars {
    int	idx;
    int	idx_line;
    int	k;
    int	value_read;
    char	buf[READ_SIZE + 1];
    char	*line;
    } t_vars;

    char **my_str_to_wordtab(char *str);
    char *get_next_line(const int fd);
    void my_putchar(char c);
    int my_putstr(char const *str);
    int	my_strncmp(char *s1, char *s2, int n);
    char **path(char **env);
    int	exec(char **arr, char **env);
    int mcd(char **arr, char **env);
    char *get_prompt(void);
    char *find_environment_variable_value(char *str, char **env);
    char **setenv(char **arr, char **env);
    char *my_strcat(char *dest, char *src);
    int my_strcmp(const char *s1, const char *s2);
    char *my_strcpy(char *dest, const char *src);
    int my_strlen(char *str);

#endif /* !MY_H_ */
