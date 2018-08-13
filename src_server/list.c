/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** list
*/

#include "my.h"

int	already_there(t_env *e, char *chan)
{
	t_channel	*tmp;
	
	tmp = e->channel_list;
	while (tmp)
	{
		if (strcmp(tmp->name, chan) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	add_list(t_env *e, char *chan)
{
	t_channel	*tmp;
	t_channel	*new;

	tmp = e->channel_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_channel));
	new->name = strdup(chan);
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		e->channel_list = new;
}

char	*chan_list(t_env *e)
{
	char		*chan_list;
	t_channel	*tmp;

	chan_list = malloc(sizeof(char) * 4096);
	tmp = e->channel_list;
	while (tmp)
	{
		if (tmp->name)
		{
			chan_list = strcat(chan_list, tmp->name);
			chan_list = strcat(chan_list, "\n");
		}
		tmp = tmp->next;
	}
	return (chan_list);
}
