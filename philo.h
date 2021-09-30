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

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	long			start_time;
	int				philos;
	int				death ;
	int				meal;
	int				sleep;
	int				eat_count;
	int				eaten;
}				t_philo;

typedef struct s_node
{
	pthread_mutex_t	fork;
	pthread_mutex_t	eating;
	pthread_mutex_t	data;
	pthread_t		sup;
	pthread_t		philo;
	int				eat;
	int				id;
	long			last_meal;
	t_philo			*all;
	struct s_node	*next;
}	t_node;

/*   parsing   */
int		check_nb(const char *str);
int		check_assign(int count, char **args, t_philo *asset);

/*   init   */
int		initials(t_philo *philo, t_node **nodes);
int		create_philo(t_philo *philo, t_node **nodes, int count);
int		launch(t_philo *philo, t_node **nodes);

/* routines */
void	taking_forks(t_node	*self);
void	eating(t_node	*self);
void	sleeping(t_node	*self);
void	*routine_philo(void	*self);
void	*routine_sup(void	*self);

/*   tools   */
long	get_time(void);
void	philo_write(char *s, t_node	*self);
void	ft_sleep(int time);

/*   linked_list  */
t_node	*a_node(int	id);
void	append(t_node **list, t_node *node);

#endif