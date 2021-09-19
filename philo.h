/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:31:45 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/19 12:38:21 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int philos;
	int death ;
	int meal;
	int sleep;
	int eat_count;
}				t_philo;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;


/*   parsing   */
int	check_nb(const char *str);
int	check_assign(int count , char **args, t_philo *asset);


#endif