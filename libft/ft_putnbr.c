/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:01:45 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/01 23:01:36 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_putnbr(long long nb, int n)
{
	if (nb < 10 && nb > -10)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= (-1);
			n++;
		}
		ft_putchar((char) nb + '0');
		n++;
	}
	else
	{
		n = ft_putnbr(nb / 10, n);
		if (nb < 0)
			ft_putchar((char)(((nb % 10) * (-1)) + '0'));
		else
			ft_putchar((char)((nb % 10) + '0'));
		n++;
	}
	return (n);
}
