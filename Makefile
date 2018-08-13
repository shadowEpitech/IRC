##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	gcc -g3

RM	=	rm -rf

SERVER	=	server
CLIENT	=	client

CFLAGS	=	-Wall -W -Wextra  -I./include/

SRC_SERVER	=	src_server/server.c	\
			src_server/client_fonction.c	\
			src_server/add_client.c	\
			src_server/main.c	\
			utils/close_file.c		\
			src_server/make_cmd.c	\
			src_server/check_cmd.c	\
			utils/my_str_to_wordtab.c	\
			src_server/list.c	\
			src_server/server_cmd.c		\
			src_server/gestion_chan.c	\
			src_server/user.c		\
			src_server/priv_msg.c		\
			src_server/send_msg.c		\
			src_server/send_channel.c	\
			src_server/make_name.c	

SRC_CLIENT	=	src_client/client.c	\
			src_client/utils_client.c	\
			src_client/checked_cmd.c	\
			src_client/error.c	\
			utils/my_str_to_wordtab.c	\
			utils/close_file.c			\
			src_client/run_channel.c	\
			src_client/make_msg.c	\
			src_client/list_users.c		\
			src_client/connect_server.c	\
			src_client/private_msg.c	\
			src_client/users.c		\
			src_client/main.c

SRC_SERVER=	$(wildcard ./src_server/*.c) \
						$(wildcard ./utils/*.c)

SRC_CLIENT=	$(wildcard ./src_client/*.c) \
						$(wildcard ./utils/*.c)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)


all:		$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ_SERVER)
		$(CC) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT):	$(OBJ_CLIENT)
		$(CC) $(OBJ_CLIENT) -o $(CLIENT)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:	all clean fclean re
