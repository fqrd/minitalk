/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:00:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 19:56:19 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int		binary_to_char(char *binary)
// {
// 	size_t i;
// 	size_t res;
// 	size_t len;

// 	len = ft_strlen(binary) - 1;
// 	i = 0;
// 	res = 0;
// 	while (binary[i])
// 	{
// 		if (binary[i] == '1')
// 			res += ft_power(2, len - i);
// 		i++;
// 	}
// 	return (res);
// }

// int	binary(int digit)
// {
// 	static int i = 0;
// 	static char *binary;

// 	if (i == 0)
// 	{
// 		binary = malloc(sizeof(char) * 8 + 1);
// 		if (!binary)
// 			return (0);
// 		binary[8] = '\0';
// 	}

// 	binary[i] = digit + '0';

// 	if (++i == 8)
// 	{
// 		ft_putchar(binary_to_char(binary));
// 		i = 0;
// 		free (binary);
// 		binary = NULL;
// 	}
// 	return (0);
// }


void	binary(int digit)
{
	static int i = 7;
	static int c = 0;

	if (digit == 1)
		c += ft_power(2, i);
	
	if (--i < 0)
	{
		ft_putchar(c);
		i = 7;
		c = 0;
	}
}

void	binary_ones(int num)
{
	if (num)
		binary(1);
}

void	binary_zeroes(int num)
{
	if (num)
		binary(0);
}

int		main(void)
{
	struct sigaction ones = {0};
	struct sigaction zeroes = {0};
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
		return (0);
	ft_putnbr(getpid(), 0);
	ft_putchar('\n');

	ones.sa_handler = binary_ones;
	zeroes.sa_handler = binary_zeroes;
	sigaction(SIGUSR1, &ones, NULL);
	sigaction(SIGUSR2, &zeroes, NULL);
	
	while (1) ;
	return (0);
}