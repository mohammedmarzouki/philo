/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:31:45 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/20 20:29:56 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_node
{
	pthread_mutex_t	fork;
	int				id;
	struct s_node	*next;
}	t_node;

typedef struct	s_philo
{
	pthread_mutex_t	write;
	int		philos;
	int		death ;
	int		meal;
	int		sleep;
	int		eat_count;
	t_node	*person;
}				t_philo;



/*   parsing   */
int	check_nb(const char *str);
int	check_assign(int count , char **args, t_philo *asset);


#endif