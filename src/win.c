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

    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (array[i][j] == 'O')
                nbr.o++;
            else if (array[i][j] == 'X')
                nbr.x++;
    return (nbr);
}

int check_win_lose(char **array, char **map)
{
    int count = 0;

    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (map[i][j] == 'O' && array[i][j] == 'X')
                count++;
    return (count);
}

int check_map(number_t nbr)
{
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