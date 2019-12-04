/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban.c
*/

#include "my.h"

void free_all(char *buffer, char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    free(buffer);
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

void display_map(char **map, char *buffer)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    while (1) {
        clear();
        for (int i = 0; i < nb_lines(buffer); i++) {
            printw(map[i]);
            printw("\n");
        }
        map = move_player(map);
        refresh();
    }
    endwin();
}
 void help(void)
 {
     my_putstr("USAGE\n     ./sokoban map\nDESCRIPTION\n");
     my_putstr("     map file representing the warehouse map, ");
     my_putstr("containing ‘#’ for walls,\n\t ‘P’ for the player, ");
     my_putstr("‘X’ for boxes and ‘O’ for storage locations.\n");
 }

int main(int ac, char **av)
{
    char *buffer = 0;
    char **array = 0;

    if (ac != 2)
        return (84);
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
            help();
    if (open_read_file(av[1]) == NULL)
        return (84);
    buffer = open_read_file(av[1]);
    array = my_str_to_word_array(buffer);
    display_map(array, buffer);
    free_all(buffer, array);
    return (0);
}