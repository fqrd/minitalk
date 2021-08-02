/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 15:00:53 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 14:42:44 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int num)
{
	static int i = 0;
	i++;
	ft_putnbr(i,0);
	ft_putchar('\n');
	if (num ==445)
		ft_putstr("ok\n");
}

int main(void)
{
	struct sigaction sa;
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
		return (0);
	ft_putnbr(getpid(), 0);
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);

	while (1) ;
	return (0);
}