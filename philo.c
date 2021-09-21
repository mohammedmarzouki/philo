/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:31:12 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 09:00:02 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philo asset;

	if (!check_assign(argc, argv, &asset))
		return (0);
	if (!initials(&asset))
		return (0);
	while (asset.philos--)
	{
		printf("%d\n",asset.person->id);
		asset.person = asset.person->next;
	}
}