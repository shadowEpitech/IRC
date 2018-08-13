/*
** EPITECH PROJECT, 2018
** By Shadow
** File description:
** server 
*/

#include "my.h"

int	create_socket()
{
	struct protoent		*proto;
	int			s;

	if ((proto = getprotobyname("TCP")) == NULL)
		my_exit("Error : can't create_socket", 84);
	if ((s = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		my_exit("Error : can't create socket", 84);
	return (s);
}

void	server_read(t_env *env, int fd)
{
	add_client(env, fd);
}

void	init_server(t_env *env, int s)
{
	env->fd_type[s] = FD_SERVER;
	env->fct_read[s] = server_read;
	env->fct_write[s] = NULL;
	env->fds[s] = s;
	env->channel_list = NULL;
}

void	add_server(t_env *env)
{
	int	s;
	struct sockaddr_in sin;

	s = create_socket();
//	s = socket(PF_INET, SOCK_STREAM, 0);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(env->port);
	sin.sin_addr.s_addr = INADDR_ANY;
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
		close_file("Error : bind, can't assign address to server", s, EXIT_FAILURE);
	if (listen(s, 42) == -1)
		close_file("Error : listen, can't create queue", s, EXIT_FAILURE);
	env->clients->host = inet_ntoa(sin.sin_addr);
	init_server(env, s);
}
