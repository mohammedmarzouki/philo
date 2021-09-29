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
	self->last_meal = get_time();
	while(1)
	{
		taking_forks(self);
		eating(self);
		sleeping(self);
		philo_write("is thinking", self);
	}
	return (NULL);
}

void	philo_write(char *s,t_node	*self)
{
	pthread_mutex_lock(&self->all->write);
	printf("%04ld %d %s\n", get_time() - self->all->start_time, self->id, s);
	pthread_mutex_unlock(&self->all->write);
}

void	eating(t_node	*self)
{
	pthread_mutex_lock(&self->eating);
	self->eat++;
	self->last_meal = get_time();
	philo_write("is eating", self);
	ft_sleep(self->all->meal);
	if (self->all->eat_count != -2 && self->eat == self->all->eat_count)
		self->all->eaten++;
	pthread_mutex_unlock(&self->eating);
	
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
