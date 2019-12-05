/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    char *buffer = 0;
    char **array = 0;
    char **map = 0;
    number_t nbr;

    if (ac != 2)
        return (84);
    if (ac == 2)
        help(av);
    if (open_read_file(av[1]) == NULL)
        return (84);
    buffer = open_read_file(av[1]);
    array = my_str_to_word_array(buffer);
    map = my_str_to_word_array(buffer);
    nbr = numer_boxes(array);
    if (check_map(nbr) != 0)
        return (84);
    display_array(array, buffer, map, nbr);
    free_all(buffer, array, map);
    return (0);
}