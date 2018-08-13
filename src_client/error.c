/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** error file
*/

#include "client.h"

void	need_more_param(t_client *client, char *cmd)
{
	char	*msg;

	msg = malloc(sizeof(char) * 512);
	sprintf(msg, "461 %s :%s\n", cmd, ERR_NEEDMOREPARAMS);
	make_msg(client, msg, 0);
}

void	no_nickname_given(t_client *client)
{
	char	*msg;

	msg = malloc(sizeof(char) * 512);
	sprintf(msg, "431 %s\n",  ERR_NONICKNAMEGIVEN);
	make_msg(client, msg, 0);
}

void	not_on_channel(t_client *client, char *channel)
{
	char	*msg;

	msg = malloc(sizeof(char) * 512);
	sprintf(msg, "443 %s :%s\n", channel, ERR_NOSUCHCHANNEL);
	make_msg(client, msg, 0);
}

