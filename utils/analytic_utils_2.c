/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytic_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:55:44 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/28 22:58:16 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_closest_superior(t_node *stack, t_node *target)
{
	t_node	*looping_node;
	t_node	*current_superior;

	looping_node = stack;
	current_superior = NULL;
	while (looping_node)
	{
		if (looping_node->rank > target->rank)
		{
			if (!current_superior)
				current_superior = looping_node;
			else
			{
				if (current_superior->rank > looping_node->rank)
					current_superior = looping_node;
			}
		}
		looping_node = looping_node->next;
	}
	return (current_superior);
}
