/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:31:27 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:47:19 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

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

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	int		stack_size;

	stack_size = argc - 1;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	stack_a = parser(argv, stack_size);
	if (!check_duplicates(stack_a))
		return (ft_putendl_fd("Error", 2), exit(1), 0);
	stack_size = ft_lstsize_int(stack_a);
	rank_nodes(stack_a, stack_size);
	handle_checker(&stack_a, stack_size);
}
