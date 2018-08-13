/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** add_client 
*/

#include "my.h"

void	add_client(t_env *e, int s)
{
	int		cs;
	struct sockaddr_in	client_sin;
	unsigned int			client_sin_len;

	client_sin_len = sizeof(client_sin);
	cs = accept(s, (struct sockaddr *)&client_sin,  &client_sin_len);
	e->fd_type[cs] = FD_CLIENT;
	e->fct_read[cs] = client_read;
	e->fct_write[cs] = client_write;
	e->fds[cs] = cs;
	e->clients[cs].nickname = name(cs);
	e->clients[cs].host = inet_ntoa(client_sin.sin_addr);
	printf("Client ! %s\n", e->clients[cs].nickname);
}
