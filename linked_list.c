/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:36:31 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/21 09:12:14 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_node	*a_node(int	id)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->id = id;
	node->next = NULL;
	return (node);
}

void	append(t_node **list, t_node *node)
{
	t_node	*head;

	if (!(*list))
	{
		node->next = node;
		*list = node;
		return ;
	}
	head = *list;
	while ((*list)->next != head)
		(*list) = (*list)->next;
	(*list)->next = node;
	node->next = head;
	(*list) = head;
}
