/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:00:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 18:27:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	binary_to_char(char *binary, int bits)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			res += ft_power(2, bits - i);
		i++;
	}
	return (res);
}

int	binary(int digit)
{
	static int i = 0;
	static char *binary;

	if (i == 0)
	{
		binary = malloc(sizeof(char) * 8 + 1);
		if (!binary)
			return (0);
		binary[8] = '\0';
	}

	binary[i] = digit + '0';

	if (++i == 8)
	{
		ft_putchar(binary_to_char(binary, 7));
		i = 0;
		free (binary);
		binary = NULL;
	}
	return (0);
}

void binary_ones(int num)
{
	if (num > 0)
		binary(1);
}

void binary_zeroes(int num)
{
	if (num > 0)
		binary(0);
}

int main(void)
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
	
	while (1){
		sigaction(SIGUSR1, &ones, NULL);
		sigaction(SIGUSR2, &zeroes, NULL);
	}
	return (0);
}