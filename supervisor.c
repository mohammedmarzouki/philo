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
	t_node *self;
	self = (t_node*)sel;
	long	diff;
	while(1)
	{   
		diff = get_time() - self->last_meal;
		// printf("%d\n",self->all->death);
		if (diff > self->all->death && !self->eat)
		{
			pthread_mutex_lock(&self->all->write);
			printf("%ld %d died\n", get_time(), self->id);
			pthread_mutex_unlock(&self->all->dead);
		}
		// else if (diff < self->all->death + 30)
		// 	usleep(25000);
		// else
		// 	usleep(200);
		usleep(100);
	}
	return (NULL);
}