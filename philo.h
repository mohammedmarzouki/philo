/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:31:45 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 11:12:15 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo t_philo;

typedef struct s_node
{
	pthread_mutex_t	fork;
	pthread_mutex_t	eating;
	int				id;
	void			*all;
	struct s_node	*next;
}	t_node;

typedef struct	s_philo
{
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	int		philosN;
	int		deathT ;
	int		mealT;
	int		sleepT;
	int		eat_count;
	t_node	*person;
}				t_philo;



/*   parsing   */
int	check_nb(const char *str);
int	check_assign(int count , char **args, t_philo *asset);

/*   init   */
int initials(t_philo *philo);
int	create_philo(t_philo *philo, int count);

/*   tools   */
long	get_time(void);

/*   linked_list  */
t_node	*a_node(int	id);
void	append(t_node **list, t_node *node);


#endif