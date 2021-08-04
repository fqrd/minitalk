/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:16:52 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/04 16:33:03 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send(char *s, int id)
{
	static int	c;
	static int	bit = -1;
	static char	*str;
	static int	pid;

	if (!str)
		str = s;
	if (id != -1)
		pid = id;
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
	(void) info;
	if (sig == SIGUSR1)
		send(NULL, -1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	ack;
	int					pid;

	if (argc < 3 || !argv[2])
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (0);
	ack.sa_flags = SA_SIGINFO;
	ack.sa_sigaction = acknowlegded;
	if (sigaction(SIGUSR1, &ack, NULL) == -1)
	{
		write(1, "Error sigaction initialization failed.\n", 39);
		return (0);
	}
	send (argv[2], pid);
	while (1)
		pause();
	return (0);
}
