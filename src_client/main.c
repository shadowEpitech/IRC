/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** main for client
*/

#include "client.h"

void	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
	struct timeval	tv;

	tv.tv_sec = 20;
	tv.tv_usec = 0;
	if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
		my_exit("Error : select !", EXIT_FAILURE);
}

void	run_client(int fd, t_client *client)
{
	fd_set	fd_read;
	fd_set	fd_write;

	while (1)
	{
		init_fct(&fd_read, &fd_write, fd);
		my_select(3, &fd_read, &fd_write);
		check_isset(&fd_read, &fd_write, fd, client);
	}
}

int	main()
{
	static int	fd;
	static	t_client	*client;

	client = init_client(client);
	while (fd <= 0)
		fd = make_connect(client);
	run_client(fd, client);
	return (0);
}
