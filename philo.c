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

int main(int argc, char **argv)
{
	t_philo asset;

	printf("%ld\n",get_time());
	usleep(5000 * 1000);
	printf("%ld\n",get_time());

	if (!check_assign(argc, argv, &asset))
		return (0);
	if (!initials(&asset))
		return (0);
	return (0);
	while (asset.philosN--)
	{
		printf("%d\n",asset.person->id);
		asset.person = asset.person->next;
	}
}