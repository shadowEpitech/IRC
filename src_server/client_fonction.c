/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** client_fonction
*/

#include "my.h"

void	client_read(t_env *e, int fd)
{
	int	r;
	char	buff[4096];
	char	**str;
	int	i;

	r = read(fd, buff, 4096);
	if (r > 0)
	{
		buff[r] = '\0';
		str = my_str_to_wordtab(buff, "\n");
		for (i = 0; str[i]; i++)
		{
			if (is_a_cmd(str[i]) == 0)
				check_cmd(make_cmd(str, i), e, fd);
			else
				send_all_channel(e, fd, str[i]);
		}
	}
	else {
		printf("%d: connection closed\n", fd);
		close(fd);
		e->fd_type[fd] = FD_FREE;
	}
}

void	client_write(t_env *e, int fd)
{
	if (e->clients[fd].msg)
	{
		dprintf(fd, "%s\r\n", e->clients[fd].msg);
		free(e->clients[fd].msg);
	}
	e->clients[fd].msg = NULL;
}
