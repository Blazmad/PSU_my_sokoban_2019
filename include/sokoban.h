/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>

typedef struct player
{
    int i;
    int j;
}player_t;

typedef struct number
{
    int o;
    int x;
}number_t;

int check_file_error(int fd, int status, int size);
char *open_read_file(char const *filepath);
char **my_str_to_word_array(char const *str);
int nb_char(char const *str);
int nb_lines(char const *str);
char **move_player(char **array, char *buffer);
char **move_player_up(char **array);
char **move_player_down(char **array);
char **move_player_left(char **array);
char **move_player_right(char **array);
number_t numer_boxes(char **array);
int check_win_lose(char **array, char **map);
int check_map(number_t nbr);
char **exam_o(char **array, char **map);
void free_all(char *buffer, char **array, char **map);
void display_array(char **array, char *buffer, char **map, number_t nbr);
void help(char **av);
player_t player_position(char **array);

#endif