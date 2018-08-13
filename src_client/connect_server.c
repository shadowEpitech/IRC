/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** connect server 
*/

#include "client.h"

void	init_connection(char *address, char *port, t_client *client)
{
	int	fd;
	struct protoent		*pe;
	struct sockaddr_in	s_in;

	if (!(pe = getprotobyname("TCP")))
		my_exit("Error : getprotobyname", 84);
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1)
	close_file("ERROR : can't create socket", fd, 84);
	s_in.sin_family = AF_INET;
	if (!port)
		s_in.sin_port = htons(PORT);
	else
		s_in.sin_port = htons(atoi(port));
	s_in.sin_addr.s_addr = inet_addr(address);
	if (connect(fd,( struct sockaddr *) &s_in, sizeof(s_in)) == -1)
		close_file("Error : can't connect", fd, 84);
	client->fd = fd;
}

void	connect_server(char *args, t_client *client)
{
	char	**tab;
	char	*msg;
	if (!args)
		make_msg(client, "USAGE: /server $host[:$port]\n", 0);
	else if (client->fd != 0)
		make_msg(client, ERR_ALREADYREGISTRED, 0);
	else
	{
		tab = my_str_to_wordtab(args, ":");
		init_connection(tab[0], tab[1], client);
		if (client->to_server)
			free(client->to_server);
		msg = malloc(sizeof(char) * 512);
		sprintf(msg, "/server %d", client->fd);
		make_msg(client, msg, 1);
		free(msg);
	}
}

int	make_connect(t_client *client)
{
	int	fd;
	int	r;
	char	buff[4096];
	char	**array;

	r = read(0, buff, 4095);
	if (r > 1)
	{
		buff[r - 1] = '\0';
		if (strncmp(buff, "/server", 7) == 0)
		{
			array = my_str_to_wordtab(buff, " ");
			if (!array[1])
			{
				printf("401 /server :%s\n", ERR_NEEDMOREPARAMS);
				return(-1);
			}
			connect_server(array[1], client);
		}
		else
			printf("USAGE: /server $host[:$port]\n");
	}
	fd  = client->fd;
	return (fd);
}
