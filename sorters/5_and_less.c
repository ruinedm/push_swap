/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_and_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:31:35 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/28 22:44:36 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_node **stack_a)
{
	int	b;
	int	c;

	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if ((*stack_a)->data > b && b > c)
	{
		rx(stack_a, STACK_A);
		sx(stack_a, STACK_A);
	}
	else if ((*stack_a)->data > b && (*stack_a)->data > c && c > b)
		rx(stack_a, STACK_A);
	else if ((*stack_a)->data > b && (*stack_a)->data < c
		&& c > (*stack_a)->data)
		sx(stack_a, STACK_A);
	else if ((*stack_a)->data < b && (*stack_a)->data > c && b > c)
	{
		rx(stack_a, STACK_A);
		rx(stack_a, STACK_A);
	}
	else if ((*stack_a)->data < b && (*stack_a)->data < c && b > c)
	{
		sx(stack_a, STACK_A);
		rx(stack_a, STACK_A);
	}
}

void	sort4(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	push_smallest(stack_a, &stack_b, STACK_A);
	sort3(stack_a);
	px(&stack_b, stack_a, STACK_A);
}

void	sort5(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	push_smallest(stack_a, &stack_b, STACK_A);
	push_smallest(stack_a, &stack_b, STACK_A);
	sort3(stack_a);
	px(&stack_b, stack_a, STACK_A);
	px(&stack_b, stack_a, STACK_A);
}
