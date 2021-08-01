/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:32:29 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/01 23:02:33 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_atoi(const char *str)
{
	long long	nbr;
	long long	add;
	int			sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (*str >= 48 && *str <= 57 && *str)
	{
		add = 10 * nbr + (*str++ - '0');
		if (add > nbr && ((add / 100) < (nbr / 10)))
			add *= (-1);
		if (add > nbr && ((add / 100) >= (nbr / 10)))
			nbr = add;
	}
	if ((add < nbr && sign == 1))
		return (-1);
	if (add < nbr && sign == -1)
		return (0);
	return ((int)(nbr * sign));
}
