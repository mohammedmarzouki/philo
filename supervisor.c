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

static	int	check_eat(t_node	*self)
{
	t_node	*hold;
	int		i;

	i = -1;
	hold = self;
	pthread_mutex_lock(&self->eating);
	while (++i < self->all->philos)
	{
		hold = hold->next;
		if (hold->eat != -1)
		{
			i = -1;
			break ;
		}
	}
	pthread_mutex_unlock(&self->eating);
	if (i != -1)
	{
		pthread_mutex_lock(&self->all->write);
		pthread_mutex_unlock(&self->all->dead);
		return (1);
	}
	return (0);
}

void	*routine_sup(void	*sel)
{
	t_node	*self;
	long	dif;

	self = (t_node *)sel;
	while (1)
	{
		pthread_mutex_lock(&self->data);
		dif = get_time(0) - self->last_meal;
		pthread_mutex_unlock(&self->data);
		if (dif > self->all->death)
		{
			pthread_mutex_lock(&self->all->write);
			printf("%04ld %d died\n", get_time(1)
				- self->all->start_time, self->id);
			pthread_mutex_unlock(&self->all->dead);
		}
		else if (self->eat < 0 && check_eat(self))
			break ;
		if (dif + 1000 < self->all->death)
			usleep(1000);
	}
	return (NULL);
}
