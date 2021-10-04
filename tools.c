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

long	get_time(int	unit)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (unit)
		return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
	return ((now.tv_sec * 1000000) + now.tv_usec);
}

void	ft_sleep(long	time)
{
	long	end;

	end = get_time(0) + (long)time;
	time = (time * 90) / 100;
	usleep(time);
	while (get_time(0) < end)
		usleep(100);
}
