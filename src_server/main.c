/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** main 
*/

#include "my.h"


int	get_fd_max(t_env *e, fd_set *fd_read, fd_set *fd_write)
{
	int	fd_max;
	int	i;

	FD_ZERO(fd_read);
	FD_ZERO(fd_write);
	fd_max = 0;
	for (i = 0; i < MAX_FD; i++)
	{
		if (e->fd_type[i] != FD_FREE)
		{
			FD_SET(i, fd_read);
			FD_SET(i, fd_write);
			fd_max = i;
		}
	}
	return (fd_max);
}

void	my_select(int	fd_max, fd_set *fd_read, fd_set *fd_write)
{
	struct timeval	tv;

	tv.tv_sec = 20;
	tv.tv_usec = 0;
	if (select (fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
		my_exit("error : select!", EXIT_FAILURE);
}

void	my_isset(t_env *e, fd_set *fd_read, fd_set *fd_write)
{
	int	i;

	for (i = 0; i < MAX_FD; i++)
	{
		if (FD_ISSET(i, fd_read))
			e->fct_read[i](e, i);
		else if (FD_ISSET(i, fd_write))
			e->fct_write[i](e, i);
	}
}

int	main(int argc, char **argv)
{
	int	fd_max;
	fd_set	fd_read;
	fd_set	fd_write;
	t_env	e;

	if (argc != 2)
		return (84);
	if (strcmp(argv[1], "-help") == 0)
	{
		fprintf(stderr, "USAGE:\t./server port\n");
		return (0);
	}
	e.port = atoi(argv[1]);
	add_server(&e);
	while (42)
	{
		fd_max = get_fd_max(&e, &fd_read, &fd_write);
		my_select(fd_max, &fd_read, &fd_write);
		my_isset(&e, &fd_read, &fd_write);
	}
	return (0);
}
