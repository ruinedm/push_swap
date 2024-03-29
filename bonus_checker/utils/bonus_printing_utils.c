/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_printing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:36:44 by mboukour          #+#    #+#             */
/*   Updated: 2024/02/08 22:25:58 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

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

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
