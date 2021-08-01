# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 14:32:22 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/01 23:46:26 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =				\
	client.c		\
	server.c
	
OBJS = $(SRCS:.c=.o)

SERVER = server
CLIENT = client

all: libs $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER).o -L libft -lft

$(CLIENT): $(OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT).o -L libft -lft

libs:
	$(MAKE) -C ./libft

clean:
	rm -f *.o

fclean: clean
	rm -f ./server ./client

re: fclean all

.PHONY: clean fclean re all