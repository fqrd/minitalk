/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:00:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/03 14:40:43 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int i = 7;
	static int c = 0;

	if (sig == SIGUSR1)
		c = (c << 1) + 1;
	else
		c <<= 1;
	if (--i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

int		main(void)
{
	struct sigaction	sig;

	ft_putnbr(getpid(), 0);
	ft_putchar('\n');
	sig.sa_flags = SA_SIGINFO;
	// sig.sa_sigaction = handler;
	sig.sa_handler = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}