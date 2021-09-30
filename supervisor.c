/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:27:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 11:57:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_sup(void	*sel)
{
	t_node	*self;
	long	dif;

	self = (t_node *)sel;
	while (1)
	{
		dif = get_time() - self->last_meal;
		if (dif > self->all->death)
		{
			pthread_mutex_lock(&self->all->write);
			printf("%04ld %d died\n", get_time()
				- self->all->start_time, self->id);
			pthread_mutex_unlock(&self->all->dead);
		}
		else if (self->all->eaten >= self->all->philos)
		{
			pthread_mutex_lock(&self->eating);
			pthread_mutex_unlock(&self->all->dead);
		}
		else if (dif + 30 < self->all->death)
			usleep(25000);
		else
			usleep(200);
	}
	return (NULL);
}
