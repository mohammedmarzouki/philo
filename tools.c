/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:27:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 11:57:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long 	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ft_sleep(int time)
{
	int		sleep;
	// int		loop;
	long	end;

	end = get_time() + (long)time;
	// printf("[%d]\n", time);
	sleep = time * 1000;
	sleep = (sleep * 90) / 100;
	// loop = time * 1000;
	// loop = (time * 10) / 100;
	usleep(sleep);
	while (get_time() < end);
}