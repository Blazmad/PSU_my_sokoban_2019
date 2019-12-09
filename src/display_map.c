/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** display_map.c
*/

#include "my.h"

void free_all(char *buffer, char **array, char **map)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
    free(buffer);
}

void display_array(char **array, char *buffer, char **map, number_t nbr)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    while (check_win_lose(array, map) != nbr.o) {
        clear();
        for (int i = 0; i < nb_lines(buffer); i++) {
            array = exam_o(array, map);
            printw(array[i]);
            printw("\n");
        }
        array = move_player(array, buffer);
        refresh();
    }
    endwin();
}

void help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE\n     ./sokoban array\nDESCRIPTION\n");
        my_putstr("     array file representing the warehouse array, ");
        my_putstr("containing ‘#’ for walls, \n\t   ‘P’ for the player, ");
        my_putstr("‘X’ for boxes and ‘O’ for storage locations.\n");
    }
}

player_t player_position(char **array)
{
    player_t pos_player = {0, 0};

    for (int i = 0; array[i]; i++)
        for (int j = 0; array[i][j]; j++)
            if (array[i][j] == 'P') {
                pos_player.i = i;
                pos_player.j = j;
            }
    return (pos_player);
}