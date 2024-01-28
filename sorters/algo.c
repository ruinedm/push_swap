/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:31:41 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/28 22:56:38 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	preform_action_alot(t_node **stack_a, t_node **stack_b, int sign,
		int times)
{
	int	i;
	int	action;

	i = 0;
	action = RX;
	if (sign < 0)
		action = RRX;
	while (i < times)
	{
		if (action == RX)
			rr(stack_a, stack_b);
		else if (action == RRX)
			rrr(stack_a, stack_b);
		i++;
	}
}

void	go_to_top(t_node **stack, t_node *target, int flag)
{
	int	pos;
	int	stack_size;

	stack_size = ft_lstsize_int(*stack);
	pos = get_node_position(*stack, target);
	if (pos <= stack_size / 2)
	{
		while ((*stack) != target)
			rx(stack, flag);
	}
	else
	{
		while ((*stack) != target)
			rrx(stack, flag);
	}
}

void	ez_push_to_place(t_node **stack_a, t_node **stack_b, t_node *to_push,
		t_node *closest_superior)
{
	go_to_top(stack_a, closest_superior, STACK_A);
	go_to_top(stack_b, to_push, STACK_B);
	px(stack_b, stack_a, STACK_A);
}

void	sort_all(t_node **stack_a, int stack_size)
{
	t_node	*stack_b;
	t_node	*to_push;
	t_node	*closest_superior;

	stack_b = NULL;
	push_with_pivot(stack_a, &stack_b, stack_size);
	while (stack_b)
	{
		iterate_and_calculate(*stack_a, stack_b);
		to_push = get_best_node(*stack_a, stack_b, ft_lstsize_int(stack_b));
		closest_superior = get_closest_superior(*stack_a, to_push);
		if (!closest_superior)
			closest_superior = get_smallest_node(*stack_a);
		if (to_push->moves[0] == 0 && to_push->moves[1] == 0)
			px(&stack_b, stack_a, STACK_A);
		else
		{
			if (to_push->moves[0] * to_push->moves[1] > 0)
				preform_action_alot(stack_a, &stack_b, to_push->moves[0],
					min(abs(to_push->moves[0]), abs(to_push->moves[1])));
			ez_push_to_place(stack_a, &stack_b, to_push, closest_superior);
		}
	}
	go_to_top(stack_a, get_smallest_node(*stack_a), STACK_A);
}
