/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

int nb_lines(char const *str)
{
    int i = 0;
    int l = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            l++;
        i++;
    }
    return (l);
}

int nb_char(char const *str)
{
    static int i = 0;
    int c = 0;

    if (i != 0)
        i++;
    while (str[i] != '\n') {
        i++;
        c++;
    }
    return (c);
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int k = 0;
    int lines = nb_lines(str);
    int nb_c = nb_char(str);
    char **array = malloc(sizeof(char *) * lines + 1);

    for (int i = 0; i < lines; i++) {
        j = 0;
        array[i] = malloc(sizeof(char) * nb_c + 1);
        while (str[k] != '\n') {
            array[i][j] = str[k];
            j++;
            k++;
        }
        array[i][j] = '\0';
        k++;
    }
    array[lines] = '\0';
    return (array);
}