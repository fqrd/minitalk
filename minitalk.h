/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:10:36 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/01 18:39:58 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.a"
// 2 exec files:
// 'server' which launches first and returns its PID.
// 'client' which takes 2 parameters. The server's PID and the string to be sent out.

// gcc client.c -o client
// gcc server.c -o server

# include <signal.h>
/**
 * signal
 * sigemptyset
 * sigaddset
 * sigaction
 * kill
 */
# include <stdlib.h>
/**
 * malloc
 * free
 */
# include <unistd.h>
/**
 * write
 * getpid
 * pause
 * sleep
 * usleep
 * exit
 */

# include <sys/types.h>
/**
 *  t_pid support
 */
# include <stdio.h>
# include <limits.h>
#endif