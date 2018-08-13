/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** priv_msg
*/

#include "my.h"

int	find_nickname(char *nickname, t_env *e)
{
	int	i;

	for (i = 0; i < MAX_FD; i++)
	{
		if (strcmp(nickname, e->clients[i].nickname) == 0)
			return (i);
	}
	return (0);
}

char	*msg_conc(char **tab)
{
	int	i;
	char	*msg;

	msg = malloc(sizeof(char) * 4096);
	msg = strcpy(msg, tab[2]);
	for (i = 3; tab[i]; i++)
	{
		strcat(msg, " ");
		strcat(msg, tab[i]);

	}
	return (msg);
}

void	send_private_msg(char *nickname, char **tab, t_env *e, int fd)
{
	int	fd_dest;
	char	*msg;

	msg = malloc(sizeof(char) * 4096);
	if ((fd_dest = find_nickname(nickname, e)) > 0)
	{
		sprintf(msg, ":%s PRIVMSG %s :%s",
			e->clients[fd].nickname, nickname, msg_conc(tab));
		e->clients[fd_dest].msg = strdup(msg);
	}
	else
	{
		sprintf(msg, "401 %s :%s", nickname, ERR_NOSUCHNICK);
		e->clients[fd].msg = strdup(msg);
	}
	free(msg);
}

