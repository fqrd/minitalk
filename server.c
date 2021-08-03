/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:00:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/03 12:08:13 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int i = 7;
	static int c = 0;

	(void)ucontext;
	(void)info;
	
	if (sig == SIGUSR1)
		c += ft_power(2, i); // too slow use should use bitwise stuff
	if (--i < 0)
	{
		if (c == 4)
			ft_putchar('\n');
		else
			ft_putchar(c);
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
	sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}