/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "client.h"

void	private_msg(char *nickname, char *msg, t_client *client, char *buff)
{
	if (!nickname)
		no_recipient(client, "/msg");
	else if (!msg)
		no_text_to_send(client);
	else
		make_msg(client, buff, 1);
}

void	no_text_to_send(t_client *client)
{
	char	*msg;
	msg = malloc(sizeof(char) * 512);
	sprintf(msg, "412 :%s\n", ERR_NOTEXTTOSEND);
	make_msg(client, msg, 0);
}

void	no_recipient(t_client *client, char *cmd)
{
	char	*msg;

	msg = malloc(sizeof(char) * 512);
	sprintf(msg, "%s (%s)\n", ERR_NORECIPIENT, cmd);
	make_msg(client, msg, 0);
}
