/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:39:47 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 02:42:32 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	min_in_arr(int *arr, int arr_size)
{
	int	min;
	int	i;

	i = 0;
	min = arr[0];
	while (i < arr_size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
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
