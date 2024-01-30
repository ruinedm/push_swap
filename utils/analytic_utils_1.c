/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytic_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:55:51 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:12:47 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_best_node(t_node *stack_a, t_node *stack_b, int stack_size)
{
	int		*choice_array;
	t_node	*best_node;
	t_node	*result;

	result = calculate_choice_array(stack_a, stack_b, stack_size,
			&choice_array);
	if (result)
		return (result);
	best_node = find_min_node(stack_b, choice_array, stack_size);
	free(choice_array);
	return (best_node);
}

t_node	*find_min_node(t_node *stack, int *choice_array, int stack_size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = min_in_arr(choice_array, stack_size);
	while (i < stack_size)
	{
		if (choice_array[i] == min)
		{
			break ;
		}
		i++;
	}
	while (j < i)
	{
		stack = stack->next;
		j++;
	}
	return (stack);
}

int	get_cost(t_node *stack, t_node *target, int stack_size)
{
	t_node	*looping_node;
	int		cost;

	cost = 0;
	if (get_node_position(stack, target) <= stack_size / 2)
	{
		looping_node = stack;
		while (looping_node != target)
		{
			looping_node = looping_node->next;
			cost++;
		}
		return (cost);
	}
	else
	{
		looping_node = target;
		while (looping_node)
		{
			looping_node = looping_node->next;
			cost++;
		}
		return (-cost);
	}
}

void	iterate_and_calculate(t_node *stack_a, t_node *stack_b)
{
	t_node	*looping_node;
	t_node	*closest_superior;
	int		*mv;
	int		stack_a_size;
	int		stack_b_size;

	stack_a_size = ft_lstsize_int(stack_a);
	stack_b_size = ft_lstsize_int(stack_b);
	looping_node = stack_b;
	while (looping_node)
	{
		mv = looping_node->moves;
		closest_superior = get_closest_superior(stack_a, looping_node);
		if (!closest_superior)
			closest_superior = get_smallest_node(stack_a);
		mv[0] = get_cost(stack_b, looping_node, stack_b_size);
		mv[1] = get_cost(stack_a, closest_superior, stack_a_size);
		looping_node = looping_node->next;
	}
}

t_node	*calculate_choice_array(t_node *stack_a, t_node *stack_b,
		int stack_size, int **choice_array_ptr)
{
	int	*choice_array;
	int	i;
	int	*mv;

	i = 0;
	choice_array = malloc(stack_size * sizeof(int));
	if (!choice_array)
		return (ft_lstclear_int(stack_a), ft_lstclear_int(stack_b),
			ft_putendl_fd("Error", 2), exit(EXIT_FAILURE), NULL);
	while (stack_b)
	{
		mv = stack_b->moves;
		if (mv[0] == 0 && mv[1] == 0)
			return (free(choice_array), *choice_array_ptr = NULL, stack_b);
		else if (mv[0] * mv[1] > 0)
			choice_array[i] = max(abs(mv[0]), abs(mv[1]));
		else
			choice_array[i] = abs(mv[0]) + abs(mv[1]);
		i++;
		stack_b = stack_b->next;
	}
	*choice_array_ptr = choice_array;
	return (NULL);
}
