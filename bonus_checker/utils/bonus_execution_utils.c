/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_execution_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:27:16 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 02:18:29 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

void	error_handler(t_node *stack_a, t_node *stack_b)
{
	ft_lstclear_int(stack_a);
	ft_lstclear_int(stack_b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	execute_move(t_node **stack_a, t_node **stack_b, char *move)
{
	if (ft_strcmp(move, "pa\n") == 0)
		return (px(stack_b, stack_a));
	else if (ft_strcmp(move, "pb\n") == 0)
		return (px(stack_a, stack_b));
	else if (ft_strcmp(move, "sa\n") == 0)
		return (sx(stack_a));
	else if (ft_strcmp(move, "sb\n") == 0)
		return (sx(stack_b));
	else if (ft_strcmp(move, "ra\n") == 0)
		return (rx(stack_a));
	else if (ft_strcmp(move, "rb\n") == 0)
		return (rx(stack_b));
	else if (ft_strcmp(move, "rra\n") == 0)
		return (rrx(stack_a));
	else if (ft_strcmp(move, "rrb\n") == 0)
		return (rrx(stack_b));
	else if (ft_strcmp(move, "ss\n") == 0)
		return (ss(stack_a, stack_b));
	else if (ft_strcmp(move, "rr\n") == 0)
		return (rr(stack_a, stack_b));
	else if (ft_strcmp(move, "rrr\n") == 0)
		return (rrr(stack_a, stack_b));
	error_handler(*stack_a, *stack_b);
}

void	handle_checker(t_node **stack_a, int stack_size)
{
	t_node	*stack_b;
	char	*move;

	stack_b = NULL;
	move = get_next_line(0);
	while (move != NULL)
	{
		execute_move(stack_a, &stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	if (!stack_b && is_sorted(*stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear_int(*stack_a);
	ft_lstclear_int(stack_b);
}
// TO IMPLEMENT PRINT COMMAND:
// else if(ft_strcmp(move, "print\n") == 0)
// {
//     puts("STACK A");
//     ft_lstiter_int(*stack_a, print);
//     puts("STACK B");
//     ft_lstiter_int(stack_b, print);
// }