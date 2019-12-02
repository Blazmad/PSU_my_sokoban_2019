/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int d = my_strlen(dest);

    while (src[i] != 0) {
        dest[d + i] = src[i];
        i++;
    }
    dest[d + i] = '\0';
    return (dest);
}