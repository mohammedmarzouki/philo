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

void	routine_philo(t_node	*self)
{
	/* taking fork */
	taking_forks(self);
	/* eating */
	/* sleeping */
	/* thinking */
}

void	philo_write(char *s,t_node	*self)
{
	pthread_mutex_lock(&((t_philo*)self->all)->write);
	
	
}
void	taking_forks(t_node	*self)
{
	if (self->id % 2)
	{
		pthread_mutex_lock(&(self->fork));
		philo_write("has taken a fork", self);
		pthread_mutex_lock(&(self->next->fork));
		philo_write("has taken a fork", self);
	}
	else
	{
		pthread_mutex_lock(&(self->next->fork));
		philo_write("has taken a fork", self);
		pthread_mutex_lock(&(self->fork));
		philo_write("has taken a fork", self);
	}
}