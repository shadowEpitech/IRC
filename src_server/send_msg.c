/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** send_msg
*/

#include "my.h"

void	send_msg(t_env *env, int fd, char *msg)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * 4096);
	sprintf(tmp, "%s", msg);
	env->clients[fd].msg = strdup(msg);
	free(msg);
}
