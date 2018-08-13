/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** checked_cmd 
*/

#include "client.h"

void	join_channel(char *channel, t_client *client, char *buff)
{
	if (!channel)
		need_more_param(client, "/join");
	else
	{
		if (get_channel(client, channel) != 0)
		{
			add_channel(client, channel);
			make_msg(client, buff, 1);
		}
	}
}

void	change_nick(char *nickname, t_client *client, char *buff)
{
	if (!nickname)
	{
		no_nickname_given(client);
		return;
	}
	if (client->nickname)
		free(client->nickname);
	client->nickname = strdup(nickname);
	make_msg(client, buff, 1);
}

void	server_cmd(char *buff, t_client *client)
{
	char	**tab;

	tab = my_str_to_wordtab(buff, " ");
	if (strncmp(tab[0], "/join", 5) == 0)
		join_channel(tab[1], client, buff);
	else if (strncmp(tab[0], "/nick", 5) == 0)
		change_nick(tab[1], client, buff);
	else if (tab[0] &&  strncmp(tab[0], "/users", 6) == 0)
		list_users(client, buff);
	else if (tab[0] && strncmp(tab[0], "/names", 6) == 0)
		list_names(tab[1], client, buff);
	else if (tab[0] && strncmp(tab[0], "/server", 7) == 0)
		connect_server(tab[1], client);
	else if (tab[0] && strncmp(tab[0], "/msg", 4) == 0)
		private_msg(tab[1], tab[2], client, buff);
	else if (tab[0] && strncmp(tab[0], "/quit", 5) == 0)
		my_exit(NULL, 0);
	else if (tab[0] && strncmp(tab[0], "/user", 5) == 0)
		users(client, buff);
	else
		make_msg(client, "421 <commande> :Unknown command\n", 0);
}

void	check_cmd(char *buff, t_client *client)
{
	if ((buff[0] == '\0') || (buff[0] == '\n'))
		return;
	if (buff[0] == '/')
		server_cmd(buff, client);
	else
	{
		if ((buff && strncmp(buff, "NICK", 4) == 0) || (strncmp(buff, "QUIT", 4) == 0))
			make_msg(client, buff, 1);
		else if (client->channel == NULL)
			make_msg(client, "You didn't enter a channel valid\n", 0);
		else
			make_msg(client, buff, 1);
	}
}

