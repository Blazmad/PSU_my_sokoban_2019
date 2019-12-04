/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** open_file.c
*/

#include "my.h"

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