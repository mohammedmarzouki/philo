/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:27:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 11:57:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void	*sel)
{
	t_node	*self;

	self = (t_node *)sel;
	self->eat = 0;
	pthread_mutex_lock(&self->data);
	self->last_meal = get_time(0);
	pthread_mutex_unlock(&self->data);
	while (1)
	{
		taking_forks(self);
		eating(self);
		if (self->eat >= self->all->eat_count && self->all->eat_count != -2)
			self->eat = -1;
		sleeping(self);
		philo_write("is thinking", self);
	}
	return (NULL);
}

void	philo_write(char *s, t_node	*self)
{
	long	a;

	pthread_mutex_lock(&self->all->write);
	a = get_time(1) - self->all->start_time;
	printf("%04ld %d %s\n", a, self->id, s);
	pthread_mutex_unlock(&self->all->write);
}

void	eating(t_node	*self)
{
	pthread_mutex_lock(&self->eating);
	pthread_mutex_lock(&self->data);
	self->last_meal = get_time(0);
	pthread_mutex_unlock(&self->data);
	philo_write("is eating", self);
	ft_sleep(self->all->meal);
	pthread_mutex_unlock(&self->eating);
	if (self->eat != -1)
		self->eat++;
}

void	sleeping(t_node	*self)
{
	philo_write("is sleeping", self);
	pthread_mutex_unlock(&(self->fork));
	pthread_mutex_unlock(&(self->next->fork));
	ft_sleep(self->all->sleep);
}

void	taking_forks(t_node	*self)
{
	pthread_mutex_lock(&(self->fork));
	philo_write("has taken a fork", self);
	pthread_mutex_lock(&(self->next->fork));
	philo_write("has taken a fork", self);
}
