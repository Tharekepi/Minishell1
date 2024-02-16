/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** my_str.c
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int	my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    while (i < n && (s1[i] != 0 || s2[i] != 0)) {
        if (s1[i] != s2[i])
            return (1);
        i++;
        }
    if (i == n)
        return (0);
    return (1);
}

int	my_strlen(char *str)
{
    int	i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != 0)
        i++;
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *result = malloc(dest_len + src_len + 1);
    if (result == NULL) {
        return NULL;
    }
    my_strcpy(result, dest);
    my_strcpy(result + dest_len, src);
    return result;
}

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
