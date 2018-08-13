/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** server_cmd
*/

#include "my.h"

int	init_cmd3(t_env *e, int fd, char **tab)
{
	if (tab[0] && strncmp(tab[0], "PRIVMSG", 7) == 0)
	{
		send_private_msg(tab[1], tab, e, fd);
		return (1);
	}
	else if (tab[0] && strncmp(tab[0], "USER", 4) == 0)
		users(e, fd, e->clients[fd].nickname);
	return (0);
}

int	init_cmd2(t_env *e, char *buff, int fd)
{
	char	**tab;

	tab = my_str_to_wordtab(buff, " ");
	if (tab[0] && strncmp(tab[0], "QUIT", 4) == 0)
	{
		printf("%d: Connection closed\n", fd);
		close(fd);
		e->fd_type[fd] = FD_FREE;
		return (1);
	}
	if (tab[0] && strncmp(tab[0], "JOIN", 5) == 0)
	{
		join_chan(tab[1], e, fd);
		return (1);
	}
	return (init_cmd3(e, fd, tab));
}
