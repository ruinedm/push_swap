/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:32:03 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:14:18 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	sx(stack_a, -1);
	sx(stack_b, -1);
	ft_putendl_fd("ss", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rx(stack_a, 5);
	rx(stack_b, 5);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrx(stack_a, 5);
	rrx(stack_b, 5);
	ft_putendl_fd("rrr", 1);
}
