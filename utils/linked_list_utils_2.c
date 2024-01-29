/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:00:56 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/29 23:16:43 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void ft_lstiter_int(t_node *head, void(*f)(int, int, int *))
{
    if(!head)
        return ;
    t_node *copy = head;
    while(copy->next)
    {
        f(copy->data, copy->rank, copy->moves);
        copy = copy->next;
    }
    f(copy->data, copy->rank, copy->moves);
}