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

int initials(t_philo *philo, t_node **nodes)
{
	int count;
	*nodes = NULL;
	count = -1;
	while (++count < philo->philos)
		if(!create_philo(philo, nodes, count))
			return (0);
	pthread_mutex_init(&(philo->dead), NULL);
	pthread_mutex_init(&(philo->write), NULL);
	pthread_mutex_lock(&(philo->dead));
	return (1);
}

int	create_philo(t_philo *philo, t_node **nodes, int count)
{
	t_node *hold;
	
	hold = a_node(count + 1);
	if (!hold)
		return (0);
	pthread_mutex_init(&(hold->fork), NULL);
	pthread_mutex_init(&(hold->eating), NULL);
	hold->all = philo;
	append(nodes, hold);
	return (1);
}