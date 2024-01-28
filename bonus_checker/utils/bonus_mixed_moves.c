/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mixed_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:31:04 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/28 23:13:15 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	sx(stack_a);
	sx(stack_b);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}
