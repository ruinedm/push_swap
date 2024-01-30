/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:11:42 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 02:43:05 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (fd < 0 || !str)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *str, int fd)
{
	if (fd < 0 || !str)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

void	handle_parse_error(t_node *stack_a)
{
	ft_lstclear_int(stack_a);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

// void print(int data, int rank, int *moves)
// {
//     printf("VALUE: %d // RANK: %d // MOVES B: %i // MOVES A: %i\n", data,
// rank, moves[0], moves[1]);
// }