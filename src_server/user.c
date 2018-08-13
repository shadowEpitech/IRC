/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** users
*/

#include "my.h"

void	users(t_env *e, int fd, char *nickname)
{
	char	*msg;

	msg = malloc(sizeof(char) * 4096);
	sprintf(msg, "001 NICK: %s connected", nickname);
	e->clients[fd].msg = strdup(msg);
	free(msg);
}
