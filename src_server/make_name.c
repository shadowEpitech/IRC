/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** make_name
*/

#include "my.h"

char	*name(int fd)
{
	char	*tmp;
	char	*buff;

	buff = malloc(sizeof(char) * 5);
	sprintf(buff, "%d", fd);
	tmp = malloc(sizeof(char ) * 512);
	strcpy(tmp, "Anonymous");
	strcat(tmp, buff);
	return (tmp);
}
