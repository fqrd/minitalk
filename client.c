/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:16:52 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 11:05:17 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		res;
	sigset_t sigset;

	if (argc < 3)
		return (0);

	pid = ft_atoi(argv[1]);
	str = argv[2];

	printf("pid: %d\n", pid);
	printf("str: %s\n", str);
	res = sigemptyset(&sigset);
	printf("sigset: %d\n", res);
}