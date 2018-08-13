/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** gestion_chan
*/

#include "my.h"

void	add_channel(t_env *e, char *chan, int fd)
{
	t_channel	*tmp;
	t_channel	*new;

	tmp = e->clients[fd].channel;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_channel));
	new->name = strdup(chan);
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		e->clients[fd].channel = new;
}

void	delete_channel(t_env *e, char *chan, int fd)
{
	t_channel	*tmp;
	t_channel	*old;

	tmp = e->clients[fd].channel;
	old = NULL;
	while (tmp)
	{
		if (strcmp(tmp->name, chan) == 0)
		{
			free(tmp->name);
			if (old)
				old->next = tmp->next;
			else
				e->clients[fd].channel = tmp->next;
			free(tmp);
			return;
		}
	}
}

int	channel_list(t_channel *fd_chan, t_channel *i_chan)
{
	t_channel	*fd_tmp;
	t_channel	*i_tmp;

	fd_tmp = fd_chan;
	while (fd_tmp)
	{
		i_tmp = i_chan;
		while (i_tmp)
		{
			if (strcmp(fd_tmp->name, i_tmp->name) == 0)
				return (0);
			i_tmp = i_tmp->next;
		}
		fd_tmp = fd_tmp->next;
	}
	return (1);
}

int	secure_channel(t_env *e, char *channel, int fd)
{
	t_channel	*tmp;
	
	if (!channel)
		return (1);
	tmp = e->clients[fd].channel;
	while (tmp)
	{
		if (strcmp(tmp->name, channel) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
