/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** check_cmd
*/

#include "my.h"

void	check_cmd(char *buff, t_env *e, int fd)
{

	if (buff[strlen(buff) - 1] == '\n')
		buff[strlen(buff) - 1] = '\0';
	if (buff[0] == '/')
		server_cmd(buff, e, fd);
	else
		if (init_cmd2(e, buff, fd) == 1)
			return;
}

void	msg_for(t_env *e, int fd, char *msg, char *nickname)
{
	char	*tmp;
        
	tmp = malloc(sizeof(char) * 4096);
	sprintf(tmp, ":%s :%s", nickname, msg);
	e->clients[fd].msg = strdup(tmp);
	free(tmp);
}

void	server_cmd(char *buff, t_env *e, int fd)
{
	char	**tab;

	tab = my_str_to_wordtab(buff, " ");
	if (tab[0] && strncmp(tab[0], "/join", 5) == 0)
		join_chan(tab[1], e, fd);
	else if (tab[0] && strncmp(tab[0], "/msg", 4) == 0)
		send_private_msg(tab[1], tab, e, fd);
}
void	join_chan(char *channel, t_env *e, int fd)
{
	char	*msg;

	msg = malloc(sizeof(char) * 4096);
	if (!channel)
		return;
	if (secure_channel(e, channel, fd) != 0)
		add_channel(e, channel, fd);
	if (already_there(e, channel) != 0)
		add_list(e, channel);
	sprintf(msg, ":%s JOIN %s", e->clients[fd].nickname, channel);
		e->clients[fd].msg = strdup(msg);
	free(msg);
}
