/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "my.h"

void	my_exit(char *msg, int value)
{
	if (msg)
		fprintf(stderr, "%s\n", msg);
	exit(value);
}

void	close_file(char *msg, int fd, int value)
{
	if (close(fd) == -1)
		my_exit(msg, value);
	my_exit(msg, value);
}
