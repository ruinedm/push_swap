/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_general_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:28:53 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 00:58:17 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

int	is_sorted(t_node *stack)
{
	t_node	*current_node;

	current_node = stack;
	while (current_node != NULL && current_node->next != NULL)
	{
		if (current_node->next->rank != current_node->rank + 1)
			return (FALSE);
		current_node = current_node->next;
	}
	return (TRUE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_valid_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= '0' && str[i] <= '9') || str[i] == '+'
				|| str[i] == '-'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// void print(int data, int rank, int *moves)
// {
//     printf("VALUE: %d // RANK: %d // MOVES B: %i // MOVES A: %i\n", data,
//	rank, moves[0], moves[1]);
// }