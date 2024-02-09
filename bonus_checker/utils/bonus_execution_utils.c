/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_execution_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:27:16 by mboukour          #+#    #+#             */
/*   Updated: 2024/02/09 19:35:43 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

static void	error_handler(t_cmd **cmd_head, t_node *stack_a)
{
	ft_lstclear_int(stack_a);
	ft_lstclear_cmd(cmd_head);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	save_cmd(t_cmd **head, char *cmd, int identifier, t_node *stack_a)
{
	t_cmd	*new_cmd_node;

	new_cmd_node = ft_lstnew_cmd(cmd, identifier);
	if (!new_cmd_node)
	{
		ft_lstclear_int(stack_a);
		ft_lstclear_cmd(head);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (!*head)
		*head = new_cmd_node;
	else
		ft_lstaddback_cmd(head, new_cmd_node);
}

t_cmd	*read_moves(t_node *stack_a)
{
	char	*move;
	int		identifier;
	t_cmd	*cmd_head;

	cmd_head = NULL;
	move = get_next_line(0);
	while (move != NULL)
	{
		identifier = identify_move(move);
		if (identifier == -1)
			error_handler(&cmd_head, stack_a);
		save_cmd(&cmd_head, move, identifier, stack_a);
		move = get_next_line(0);
	}
	return (cmd_head);
}

void	handle_checker(t_node **stack_a)
{
	t_node	*stack_b;
	t_cmd	*cmd_head;
	t_cmd	*original;

	stack_b = NULL;
	cmd_head = read_moves(*stack_a);
	original = cmd_head;
	while (cmd_head)
	{
		execute_move(stack_a, &stack_b, cmd_head);
		cmd_head = cmd_head->next;
	}
	if (!stack_b && is_sorted(*stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear_cmd(&original);
	ft_lstclear_int(*stack_a);
	ft_lstclear_int(stack_b);
}
