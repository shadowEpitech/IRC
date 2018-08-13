/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef	MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <netdb.h>
#include <dirent.h>
#include <ctype.h>
#include "utils.h"

typedef	void(*fct)();

typedef struct s_client
{
	char	*host;
	char	*username;
	char	*nickname;
        t_channel	*channel;
	char		*msg;
}		t_client;

typedef struct s_env
{
	char	fd_type[MAX_FD];
	fct	fct_read[MAX_FD];
	fct	fct_write[MAX_FD];
	int	port;

	int	fds[MAX_FD];
	t_client	clients[MAX_FD];
	t_channel	*channel_list;
}		t_env;


void	server_read(t_env *env, int fd);
void	init_server(t_env *env, int s);
void	add_server(t_env *env);
void	add_client(t_env *e, int s);
void	client_read(t_env *e, int fd);
int	get_fd_max(t_env *e, fd_set *fd_read, fd_set *fd_write);
void	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write);
int	main(int argc, char **argv);
void	my_isset(t_env *e, fd_set *fd_read, fd_set *fd_write);
void	my_exit(char *msg, int value);
void	closing(char *msg, int fd, int value);
char	*name(int fd);
void	client_write(t_env *e, int fd);
int	find_chara(char *str, char c);
int	my_countdword(char *str, char *delim);
char	**my_putstr_indtab(char *str, char **tab, char *delim);
char	**my_countdchar(char *str, char **tab, char *delim);
char	**my_strd_to_wordtab(char *str, char *delim);
void	send_all_channel(t_env *env, int fd, char *msg);
int	is_maj(char *line);
int	is_a_cmd(char *line);
char	*make_cmd(char **tab, int pos);
void	check_cmd(char *buff, t_env *e, int fd);
void	msg_for(t_env *e, int fd, char *msg, char *nickname);
void	server_cmd(char *buff, t_env *e, int fd);
void	join_chan(char *channel, t_env *e, int fd);
int	init_cmd3(t_env *e, int fd, char **tab);
int	init_cmd2(t_env *e, char *buff, int fd);
void	add_channel(t_env *e, char *chan, int fd);
void	delete_channel(t_env *e, char *chan, int fd);
int	channel_list(t_channel *fd_chan, t_channel *i_chan);
int	secure_channel(t_env *e, char *channel, int fd);
int	already_there(t_env *e, char *channel);
void	add_list(t_env *e, char *channel);
char	*chan_list(t_env *e);
void	list_names(char *channel, t_env *e, int fd);
void	users(t_env *e, int fd, char *nickname);
int	find_nickname(char *nickname, t_env *e);
char	*msg_conc(char **tab);
void	send_private_msg(char *nickname, char **tab, t_env *e, int fd);
void	list_users(t_env *e, int fd);
void	list_names(char *channel, t_env *e, int fd);
void	send_msg(t_env *env, int fd, char *msg);
int	create_socket();

#endif /* ! MY_H_ */
