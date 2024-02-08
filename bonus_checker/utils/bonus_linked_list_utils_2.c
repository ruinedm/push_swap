/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_linked_list_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:11:00 by mboukour          #+#    #+#             */
/*   Updated: 2024/02/08 22:25:07 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

int	ft_lstsize_int(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_cmd	*ft_lstnew_cmd(char *cmd, int identifier)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->cmd = cmd;
	node->indentifier = identifier;
	node->next = NULL;
	return (node);
}

t_cmd	*ft_lstlast_cmd(t_cmd *node)
{
	t_cmd	*last_cmd;

	last_cmd = node;
	while (last_cmd->next != NULL)
		last_cmd = last_cmd->next;
	return (last_cmd);
}

void	ft_lstaddback_cmd(t_cmd **ptr_to_node, t_cmd *node_to_add)
{
	t_cmd	*last_cmd;

	if (!*ptr_to_node)
		*ptr_to_node = node_to_add;
	else
	{
		last_cmd = ft_lstlast_cmd(*ptr_to_node);
		last_cmd->next = node_to_add;
	}
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	t_cmd	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free((*lst)->cmd);
		free(*lst);
		*lst = tmp;
	}
}
// void ft_lstiter_int(t_node *head, void(*f)(int, int, int *))
// {
//     if(!head)
//     {
//         puts("HEAD IS EMPTY");
//         return ;
//     }
//     t_node *copy = head;
//     while(copy->next)
//     {
//         f(copy->data, copy->rank, copy->moves);
//         copy = copy->next;
//     }
//     f(copy->data, copy->rank, copy->moves);
// }