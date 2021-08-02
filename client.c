/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:16:52 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 18:34:14 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


char * to_binary(int c, char *res, int bits)
{
	int j;
	int b;

	j = 0;
	while (bits >= 0)
	{
		b = c >> bits;
		if (b & 1)
			res[j] = '1';
		else
			res[j] = '0';
		bits--;
		j++;
	}
	return (res);
}

char	*char_to_binary(int c)
{
	char *binary;
	
	if (c > 255)
		return (NULL);
	binary = malloc(sizeof(char) * 8 + 1);
	if (!binary)
		return (NULL);
	binary[8] = '\0';
	to_binary(c, binary, 7);
	return (binary);
}

int		main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	char	*binary;
	int		i;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	binary = NULL;
	i = 0;

	printf("pid: %d\n", pid);
	printf("str: %s\n", str);

	while (*str)
	{
		binary = char_to_binary(*str++);
		if (!binary)
			return (0);
		while (binary[i])
		{
			ft_putchar(binary[i]);
			if (binary[i] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(280);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		free(binary);
		binary = NULL;
	}
	return (0);
}