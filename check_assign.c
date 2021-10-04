/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:19:38 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 10:26:21 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nb(const char *str)
{
	long	resultat;
	int		i;

	resultat = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultat = resultat * 10 + (*str) - '0';
		if (resultat > 2147483647)
			return (-1);
		str++;
	}
	return ((int)resultat);
}

int	check_assign(int count, char **args, t_philo *asset)
{
	if (count != 5 && count != 6)
		return (0);
	asset->philos = check_nb(args[1]);
	asset->death = check_nb(args[2]);
	asset->meal = check_nb(args[3]);
	asset->sleep = check_nb(args[4]);
	if (args[5])
		asset->eat_count = check_nb(args[5]);
	else
		asset->eat_count = -2;
	if (asset->philos > 200 || asset->philos < 1
		|| asset->eat_count == -1 || asset->eat_count == 0)
		return (0);
	if (asset->death < 60 || asset->meal < 60 || asset->sleep < 60)
		return (0);
	asset->death *= 1000;
	asset->meal *= 1000;
	asset->sleep *= 1000;
	return (1);
}
