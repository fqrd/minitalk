/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:16:52 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/03 19:32:53 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char *s, int pid)
{
	static int	c = 0;
	static int	bit = -1;
	static char *str = NULL;

	if (!str)
		str = s;
	if (bit < 0)
	{
		c = *str++;
		if (!c)
			exit(0);
		bit = 7;
	}

	if ((c >> bit--) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	acknowlegded(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;

	if (sig == SIGUSR1)
		send(NULL, info->si_pid);
}

int		main(int argc, char *argv[])
{
	struct sigaction	ack;
	int		pid;
	char	*str;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ack.sa_flags = SA_SIGINFO;
	ack.sa_sigaction = acknowlegded;
	if (sigaction(SIGUSR1, &ack, NULL) == -1)
		write(1, "error client\n", 13);
	send (str, pid);
	while (1)
		pause();
	return (0);
}
