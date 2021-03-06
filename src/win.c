/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** win.c
*/

#include "my.h"

number_t numer_boxes(char **array)
{
    number_t nbr;
    nbr.o = 0;
    nbr.x = 0;

    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (array[i][j] == 'O')
                nbr.o++;
            else if (array[i][j] == 'X')
                nbr.x++;
    return (nbr);
}

int check_win(char **array, char **map)
{
    int count = 0;

    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (map[i][j] == 'O' && array[i][j] == 'X')
                count++;
    return (count);
}

int check_map(number_t nbr, char **array)
{
    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (array[i][j] != 'O' && array[i][j] != 'X' && array[i][j] != 'P'
                && array[i][j] != '#' && array[i][j] != '\n'
                && array[i][j] != ' ')
                    return (1);
    if (nbr.o != nbr.x)
        return (1);
    return (0);
}

char **exam_o(char **array, char **map)
{
    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (map[i][j] == 'O' && array[i][j] != 'P' && array[i][j] != 'X')
                array[i][j] = 'O';
    return (array);
}