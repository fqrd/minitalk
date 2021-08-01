# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 14:32:22 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/01 18:45:56 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

$(LIBFT):
	cd ./libft && $(MAKE)

all: $(LIBFT)
	$(CC) $(CFLAGS) client.c -o HEYEY

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: clean fclean re all