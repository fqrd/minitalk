/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 17:10:36 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/02 10:47:10 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/include/libft.h"
// 2 exec files:
// 'server' which launches first and returns its PID.
// 'client' which takes 2 parameters. The server's PID and the string to be sent out.

// gcc client.c -o client
// gcc server.c -o server

# include <signal.h>
/**
 * signal
 * sigemptyset  (return 0 success; -1 error)
 * sigaddset (return 0 success; -1 error)
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