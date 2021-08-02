/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:05:46 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 13:44:49 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stddef.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_putchar(unsigned char c);
int		ft_putnbr(long long nb, int n);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);

#endif