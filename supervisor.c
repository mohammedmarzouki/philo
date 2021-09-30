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
	t_node	*hold;
	t_node	*self;
	long	dif;
	int i;

	self = (t_node *)sel;
	hold = self;
	while (1)
	{
		pthread_mutex_lock(&self->data);
		dif = get_time() - self->last_meal;
		pthread_mutex_unlock(&self->data);
		if (dif > self->all->death)
		{
			pthread_mutex_lock(&self->all->write);
			printf("%04ld %d died\n", get_time()
				- self->all->start_time, self->id);
			pthread_mutex_unlock(&self->all->dead);
		}
		else if (self->eat < 0)
		{
			i = -1;
			while(hold->eat < 0 && ++i < self->all->philos)
				hold = hold->next;
			if(hold->eat != 0)
			{
				pthread_mutex_lock(&self->all->write);
				pthread_mutex_unlock(&self->all->dead);
			}
		}
		else
			usleep(200);
	}
	return (NULL);
}
