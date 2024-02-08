/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:06:31 by mboukour          #+#    #+#             */
/*   Updated: 2024/02/08 22:25:29 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

int	identify_move(char *move)
{
	if (ft_strcmp(move, "pa\n") == 0)
		return (PA);
	else if (ft_strcmp(move, "pb\n") == 0)
		return (PB);
	else if (ft_strcmp(move, "sa\n") == 0)
		return (SA);
	else if (ft_strcmp(move, "sb\n") == 0)
		return (SB);
	else if (ft_strcmp(move, "ra\n") == 0)
		return (RA);
	else if (ft_strcmp(move, "rb\n") == 0)
		return (RB);
	else if (ft_strcmp(move, "rra\n") == 0)
		return (RRA);
	else if (ft_strcmp(move, "rrb\n") == 0)
		return (RRB);
	else if (ft_strcmp(move, "ss\n") == 0)
		return (SS);
	else if (ft_strcmp(move, "rr\n") == 0)
		return (RR);
	else if (ft_strcmp(move, "rrr\n") == 0)
		return (RRR);
	return (-1);
}

void	execute_move(t_node **stack_a, t_node **stack_b, t_cmd *cmd)
{
	if (cmd->indentifier == PA)
		return (px(stack_b, stack_a));
	else if (cmd->indentifier == PB)
		return (px(stack_a, stack_b));
	else if (cmd->indentifier == SA)
		return (sx(stack_a));
	else if (cmd->indentifier == SB)
		return (sx(stack_b));
	else if (cmd->indentifier == RA)
		return (rx(stack_a));
	else if (cmd->indentifier == RB)
		return (rx(stack_b));
	else if (cmd->indentifier == RRA)
		return (rrx(stack_a));
	else if (cmd->indentifier == RRB)
		return (rrx(stack_b));
	else if (cmd->indentifier == SS)
		return (ss(stack_a, stack_b));
	else if (cmd->indentifier == RR)
		return (rr(stack_a, stack_b));
	else if (cmd->indentifier == RRR)
		return (rrr(stack_a, stack_b));
}
