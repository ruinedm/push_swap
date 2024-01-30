/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:32:43 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:46:48 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_node *stack)
{
	t_node	*current_node;
	t_node	*looping_node;

	current_node = stack;
	while (current_node->next)
	{
		looping_node = current_node->next;
		while (looping_node)
		{
			if (current_node->data == looping_node->data)
				return (0);
			looping_node = looping_node->next;
		}
		current_node = current_node->next;
	}
	return (1);
}

int	is_sorted(t_node *stack)
{
	t_node	*current_node;

	current_node = stack;
	while (current_node != NULL && current_node->next != NULL)
	{
		if (current_node->next->rank != current_node->rank + 1)
			return (FALSE);
		current_node = current_node->next;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	int		stack_size;
	t_node	*stack_a;

	stack_a = NULL;
	stack_size = argc - 1;
	if (argc == 1)
		return (0);
	stack_a = parser(argv, stack_size);
	if (!check_duplicates(stack_a))
		return (ft_putendl_fd("Error", 2), 0);
	rank_nodes(stack_a, stack_size);
	if (is_sorted(stack_a))
		return (0);
	stack_size = ft_lstsize_int(stack_a);
	sort_handler(&stack_a, stack_size);
	ft_lstclear_int(stack_a);
}
