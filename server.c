/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:00:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/03 19:31:27 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int i = 7;
	static int c = 0;

	(void)ucontext;
	c <<= 1;
	if (sig == SIGUSR1)
		c++;
	if (--i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int		main(void)
{
	struct sigaction	sig;

	ft_putnbr(getpid(), 0);
	ft_putchar('\n');
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sig, 0) == -1)
		write(1, "error\n", 6);
	if (sigaction(SIGUSR2, &sig, 0) == -1)
		write(1, "error\n", 6);
	while (1)
		pause();
	return (0);
}