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

char **my_str_to_word_array(char const *str);
int nb_char(char const *str);
int nb_lines(char const *str);
int check_file_error(int fd, int status, int size);
char *open_read_file(char const *filepath);
char **move_player(char **array);
player_t player_position(char **array);

#endif