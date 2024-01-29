/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_execution_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:27:16 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/29 23:13:10 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

void	error_handler(t_node *stack_a, t_node *stack_b)
{
	ft_lstclear_int(stack_a);
	ft_lstclear_int(stack_b);
	printf("Error\n");
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
	if (ft_lstsize_int(*stack_a) == stack_size && is_sorted(*stack_a))
		printf("OK\n");
	else
		printf("KO\n");
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