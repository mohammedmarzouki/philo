/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:36:31 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/09/19 12:41:18 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_node	*a_node(int	value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	append(t_node **list, t_node *node)
{
	t_node	*head;

	if (!node || !list)
		return ;
	if (!(*list))
	{
		node->next = node;
		*list = node;
		return ;
	}
	head = *list;
	node->next = head;
}

t_node	*pop(t_node **list)
{
	t_node	*ret;

	if ((!list || !*list))
		return (NULL);
	ret = *list;
	*list = ret->next;
	ret->next = NULL;
	return (ret);
}

void	insert(t_node **list, t_node *node)
{
	if (!node || !list)
		return ;
	if (!(*list))
	{
		node->next = node;
		*list = node;
		return ;
	}
	node->next = *list;
	*list = node;
}