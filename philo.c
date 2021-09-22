/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:31:12 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 10:23:13 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int launch(t_philo *philo, t_node **nodes)
{
	int count;
	count = -1;

	while (++count < philo->philos)
	{
		if(pthread_create(&(*nodes)->philo, NULL, routine_philo, (*nodes)))
			return (0);
		if(pthread_create(&(*nodes)->sup, NULL, routine_sup, (*nodes)))
			return (0);
		*nodes = (*nodes)->next;
		// if (count % 2 == 0)
		// 	usleep(100);
	}
	count = -1;
	pthread_mutex_lock(&philo->dead);
	while (++count < philo->philos)
	{
		pthread_detach((*nodes)->philo);
		pthread_detach((*nodes)->sup);
		*nodes = (*nodes)->next;
	}

	return(1);
}

int main(int argc, char **argv)
{
	t_philo asset;
	t_node	*nodes;
	printf("%ld\n",get_time());
	if (!check_assign(argc, argv, &asset))
		return (0);
	if (!initials(&asset, &nodes))
		return (0);
	if (!launch(&asset, &nodes))
		return(0);
	return (0);

}