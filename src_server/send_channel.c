/*
** EPITECH PROJECT, 2018
** by Shadow
** File description:
** send_channel
*/

#include "my.h"

void	send_all_channel(t_env *env, int fd, char *msg)
{
	int	i;

	if (env->clients[fd].channel != NULL)
	{
		for (i = 0;i < MAX_FD; i++)
		{
			if ((env->fd_type[i] == FD_CLIENT && env->fds[i] != 0 &&
			     env->fds[i] != fd && channel_list(env->clients[fd].channel, env->clients[i].channel) == 0))
			    msg_for(env, i, msg, env->clients[fd].nickname);
		}
	}
}
