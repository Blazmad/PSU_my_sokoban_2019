/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player.c
*/

#include "my.h"

char **move_player_up(char **array)
{
    player_t pos = player_position(array);

    if (array[pos.i - 1][pos.j] != '#' && array[pos.i - 1][pos.j] != 'X'
        && array[pos.i - 1][pos.j] != 'O') {
        array[pos.i - 1][pos.j] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    if (array[pos.i - 1][pos.j] == 'X' && array[pos.i - 2][pos.j] != '#'
        && array[pos.i - 2][pos.j] != 'X') {
        array[pos.i - 2][pos.j] = 'X';
        array[pos.i - 1][pos.j] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    return (array);
}

char **move_player_down(char **array)
{
    player_t pos = player_position(array);

    if (array[pos.i + 1][pos.j] != '#' && array[pos.i + 1][pos.j] != 'X'
        && array[pos.i + 1][pos.j] != 'O') {
        array[pos.i + 1][pos.j] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    if (array[pos.i + 1][pos.j] == 'X' && array[pos.i + 2][pos.j] != '#'
        && array[pos.i + 2][pos.j] != 'X') {
        array[pos.i + 2][pos.j] = 'X';
        array[pos.i + 1][pos.j] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    return (array);
}

char **move_player_left(char **array)
{
    player_t pos = player_position(array);

    if (array[pos.i][pos.j - 1] != '#' && array[pos.i][pos.j - 1] != 'X'
        && array[pos.i][pos.j - 1] != 'O') {
        array[pos.i][pos.j - 1] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    if (array[pos.i][pos.j - 1] == 'X' && array[pos.i][pos.j - 2] != '#'
        && array[pos.i][pos.j - 2] != 'X') {
        array[pos.i][pos.j - 2] = 'X';
        array[pos.i][pos.j - 1] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    return (array);
}

char **move_player_right(char **array)
{
    player_t pos = player_position(array);

    if (array[pos.i][pos.j + 1] != '#' && array[pos.i][pos.j + 1] != 'X'
        && array[pos.i][pos.j + 1] != 'O') {
        array[pos.i][pos.j + 1] = 'P';
        array[pos.i][pos.j] = ' ';
    }
    if (array[pos.i][pos.j + 1] == 'X' && array[pos.i][pos.j + 2] != '#'
        && array[pos.i][pos.j + 2] != 'X') {
        array[pos.i][pos.j + 2] = 'X';
        array[pos.i][pos.j + 1] = 'P';
        array[pos.i][pos.j] = ' ';
    }

    return (array);
}

char **move_player(char **array)
{
    int mov = getch();

    switch (mov) {
    case KEY_UP:
        array = move_player_up(array);
        break;
    case KEY_DOWN:
        array = move_player_down(array);
        break;
    case KEY_LEFT:
        array = move_player_left(array);
        break;
    case KEY_RIGHT:
        array = move_player_right(array);
        break;
    }
    return (array);
}