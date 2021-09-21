/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initials.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:23:15 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 11:13:13 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int initials(t_philo *philo)
{
	int count;

	count = -1;
	while (++count < philo->philosN)
		if(!create_philo(philo, count))
			return (0);
	pthread_mutex_init(&(philo->dead), NULL);
	pthread_mutex_init(&(philo->write), NULL);
	return (1);
}

int	create_philo(t_philo *philo, int count)
{
	t_node *hold;
	
	hold = a_node(count + 1);
	if (!hold)
		return (0);
	pthread_mutex_init(&(hold->fork), NULL);
	pthread_mutex_init(&(hold->eating), NULL);
	hold->all = philo;
	append(&(philo->person), hold);
	return (1);
}