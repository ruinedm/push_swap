/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:32:08 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 02:02:35 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	px(t_node **s_stack, t_node **r_stack, int flag)
{
	t_node	*tmp;

	if (flag == STACK_A)
		ft_putendl_fd("pa", 1);
	else if (flag == STACK_B)
		ft_putendl_fd("pb", 1);
	tmp = *s_stack;
	if (*s_stack != NULL)
	{
		*s_stack = (*s_stack)->next;
		if (*s_stack != NULL)
			(*s_stack)->prev = NULL;
		ft_lstaddfront_int(r_stack, tmp);
	}
}

void	rx(t_node **stack, int flag)
{
	t_node	*first;
	t_node	*last;

	if (flag == STACK_A)
		ft_putendl_fd("ra", 1);
	else if (flag == STACK_B)
		ft_putendl_fd("rb", 1);
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast_int(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rrx(t_node **stack, int flag)
{
	t_node	*looping_node;
	t_node	*last;

	if (flag == STACK_A)
		ft_putendl_fd("rra", 1);
	else if (flag == STACK_B)
		ft_putendl_fd("rrb", 1);
	if (!*stack || ft_lstsize_int(*stack) == 1)
		return ;
	last = ft_lstlast_int(*stack);
	looping_node = *stack;
	while (looping_node->next != last)
		looping_node = looping_node->next;
	looping_node->next = NULL;
	last->prev = NULL;
	ft_lstaddfront_int(stack, last);
}

void	sx(t_node **stack, int flag)
{
	t_node	*first_node;
	t_node	*second_node;

	if (flag == STACK_A)
		ft_putendl_fd("sa", 1);
	else if (flag == STACK_B)
		ft_putendl_fd("sb", 1);
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}
