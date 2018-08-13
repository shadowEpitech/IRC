/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** make msg 
*/

#include "client.h"

void	make_msg(t_client *client, char *msg, int nb)
{
	if (nb == 0)
	{
		if (client->to_client)
			free(client->to_client);
		client->to_client = strdup(msg);
	}
	else if (nb == 1)
	{
		if (client->to_server)
			free(client->to_server);
		client->to_server = strdup(msg);
	}
}
