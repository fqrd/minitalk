# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 14:32:22 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/04 16:34:35 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./srcs/

SERVER_SRCS = 					\
	$(SRC_FOLDER)server.c		\
	$(SRC_FOLDER)ft_atoi.c		\
	$(SRC_FOLDER)minitalk_utils.c

CLIENT_SRCS =					\
	$(SRC_FOLDER)client.c		\
	$(SRC_FOLDER)ft_atoi.c		\
	$(SRC_FOLDER)minitalk_utils.c
	
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)

clean:
	rm -f $(SRC_FOLDER)*.o

fclean: clean
	rm -f ./server ./client

re: fclean all

.PHONY: clean fclean re all