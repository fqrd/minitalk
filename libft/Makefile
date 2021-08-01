# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:10:36 by fcaquard          #+#    #+#              #
#    Updated: 2021/08/01 23:02:30 by fcaquard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS =				\
	ft_atoi.c		\
	ft_isspace.c	\
	ft_putchar.c	\
	ft_putnbr.c		\
	ft_putstr.c		\
	ft_strlen.c		

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: clean fclean re all