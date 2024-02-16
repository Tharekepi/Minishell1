/*
** EPITECH PROJECT, 2022
** B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
** File description:
** my_str_to_wordtab.c
*/

#include "my.h"

static int count_words(char *str);
static int copy_word(char *dest, char *src);

int str_to_tab_c(char **tab, int j)
{
    if (tab[j] == NULL) {
                return NULL;
            }
}

char **my_str_to_wordtab(char *str)
{
    char **tab;
    int i, j, count;
    count = count_words(str);
    tab = (char **)malloc(sizeof(char *) * (count + 1));
    if (tab == NULL) {
        return NULL;
    }
    j = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ' ||
        str[i - 1] == '\t') && str[i] != '\t') {
            tab[j] = (char *)malloc(sizeof(char) *
            (copy_word(NULL, &str[i]) + 1));
            str_to_tab_c(tab,j);
            copy_word(tab[j], &str[i]);
            j++;
        }
    }
    tab[count] = NULL;
    return tab;
}

static int count_words(char *str)
{
    int i, count = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ' ||
        str[i - 1] == '\t') && str[i] != '\t') {
            count++;
        }
    }
    return count;
}

static int copy_word(char *dest, char *src)
{
    int i;
    for (i = 0; src[i] != ' ' && src[i] != '\0' && src[i] != '\t'; i++) {
        if (dest != NULL) {
            dest[i] = src[i];
        }
    }
    if (dest != NULL) {
        dest[i] = '\0';
    }
    return i;
}
