/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rank_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:31:21 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:42:48 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

static int	*copy_stack_to_array(t_node *stack)
{
	int	*copy_array;
	int	stack_size;
	int	i;

	i = 0;
	stack_size = ft_lstsize_int(stack);
	copy_array = malloc(stack_size * sizeof(int));
	if (!copy_array)
		return (NULL);
	while (i < stack_size)
	{
		copy_array[i] = stack->data;
		stack = stack->next;
		i++;
	}
	return (copy_array);
}

static void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	rank_nodes(t_node *stack_a, int stack_size)
{
	t_node	*looping_node;
	int		*copy_array;
	int		i;

	i = 0;
	stack_size = ft_lstsize_int(stack_a);
	copy_array = copy_stack_to_array(stack_a);
	if (!copy_array)
	{
		ft_lstclear_int(stack_a);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	bubble_sort(copy_array, stack_size);
	looping_node = stack_a;
	while (i < stack_size)
	{
		while (looping_node->data != copy_array[i])
			looping_node = looping_node->next;
		looping_node->rank = i + 1;
		looping_node = stack_a;
		i++;
	}
	free(copy_array);
}
