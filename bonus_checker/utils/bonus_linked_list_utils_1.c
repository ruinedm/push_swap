/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_linked_list_utils_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:30:59 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/28 23:12:27 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

t_node	*ft_lstnew_int(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->rank = -1;
	node->moves[0] = 0;
	node->moves[1] = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*ft_lstlast_int(t_node *node)
{
	t_node	*last_node;

	last_node = node;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

void	ft_lstaddback_int(t_node **ptr_to_node, t_node *node_to_add)
{
	t_node	*last_node;

	if (!*ptr_to_node)
		*ptr_to_node = node_to_add;
	else
	{
		last_node = ft_lstlast_int(*ptr_to_node);
		last_node->next = node_to_add;
		node_to_add->prev = last_node;
	}
}

void	ft_lstaddfront_int(t_node **ptr_to_node, t_node *node_to_add)
{
	if (node_to_add)
	{
		node_to_add->next = *ptr_to_node;
		node_to_add->prev = NULL;
		if (*ptr_to_node)
			(*ptr_to_node)->prev = node_to_add;
		*ptr_to_node = node_to_add;
	}
}

void	ft_lstclear_int(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
