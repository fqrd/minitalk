/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:16:52 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 20:03:36 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	to_binary(int c, int bits, int pid)
{
	int b;

	while (bits >= 0)
	{
		b = c >> bits;
		if (b & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5);
		bits--;
	}
}

int		main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
		to_binary(*str++, 7, pid);
	return (0);
}
