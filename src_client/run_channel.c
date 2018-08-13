/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** manage channel
*/

#include "client.h"

int	check_channel(char *channel)
{
	int	i;

	if ((channel[0] != '&' && channel[0] != '#')
	    || strlen(channel) > MAX_LEN_CHANNEL)
		return (1);
	for (i = 0; channel[i]; i++)
	{
		if ((channel[i] == ",") || (channel[i] == ' '))
			return (1);
	}
	return (0);
}

void	add_channel(t_client *client, char *channel)
{
	t_channel	*tmp;
	t_channel	*new;

	tmp = client->channel;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_channel));
	new->name = strdup(channel);
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		client->channel = new;
}

void	drop_channel(t_client *client, char *channel)
{
	t_channel	*tmp;
	t_channel	*old;

	tmp = client->channel;
	old = NULL;
	while (tmp)
	{
		if (strcmp(tmp->name, channel) == 0)
		{
			free(tmp->name);
			if (old)
				old->next = tmp->next;
			else
				client->channel = tmp->next;
			free(tmp);
			return;
		}
		old = tmp;
		tmp = tmp->next;
	}
}

int	get_channel(t_client *client, char *channel)
{
	t_channel	*tmp;

	tmp = client->channel;
	while (tmp)
	{
		if (strcmp(tmp->name, channel) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
