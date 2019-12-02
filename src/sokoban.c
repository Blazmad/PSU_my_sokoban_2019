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

int check_file_error(int fd, int status, int size)
{
    if (fd == -1)
        return (84);
    if (size == 0)
        return (84);
    if (status == -1)
        return (84);
    if (status < size)
        return (84);
    if (status == size)
        return (0);
    return (0);
}

char *open_read_file(char const *filepath)
{
    struct stat file;
    int fd = open(filepath, O_RDONLY);
    char *buff;
    int status = 1;

    stat(filepath, &file);
    buff = malloc(sizeof(char) * file.st_size + 1);
    status = read(fd, buff, file.st_size);
    if (check_file_error(fd, status, file.st_size) != 0)
        return (NULL);
    buff[file.st_size] = '\0';
    close(fd);
    return (buff);
}

void display_map(char **array, char *buffer)
{
    initscr();
    for (int i = 0; i < nb_lines(buffer); i++) {
        printw(array[i]);
        printw("\n");
    }
    refresh();
    while (getch() != ' ');
    endwin();

}


int main(int ac, char **av)
{
    char *buffer = 0;
    char **array = 0;

    if (ac != 2)
        return (84);
    if (open_read_file(av[1]) == NULL)
        return (84);
    buffer = open_read_file(av[1]);
    array = my_str_to_word_array(buffer);
    display_map(array, buffer);
    free_all(buffer, array);
    return (0);
}