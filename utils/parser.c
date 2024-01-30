/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:32:12 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:32:03 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	str_type(char *str)
{
	int	i;

	i = 0;
	if (!is_valid_chars(str))
		return (INVALID_INPUT);
	while ((str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == ft_strlen(str))
		return (NORMAL_NUM);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i == ft_strlen(str) - 1)
				return (INVALID_INPUT);
			if (!(i == 0 || str[i - 1] == ' '))
				return (INVALID_INPUT);
		}
		i++;
	}
	return (COMPLICATED_INPUT);
}

static t_node	*add_to_list(t_node **head, char *str)
{
	int		value;
	t_node	*current_node;

	value = ft_atoi(str, *head);
	current_node = ft_lstnew_int(value);
	ft_lstaddback_int(head, current_node);
	return (*head);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c && in_word == 1)
			in_word = 0;
		i++;
	}
	return (count);
}

void	handle_complicated_input(t_node **head, char **argv, int i, char *str)
{
	int	wc;

	wc = 0;
	while (wc < word_count(argv[i + 1], ' '))
	{
		while (*str && *str == ' ')
			str++;
		*head = add_to_list(head, str);
		while (*str != ' ' && *str != '\0')
			str++;
		if (!head)
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		wc++;
	}
}

t_node	*parser(char *argv[], int stack_size)
{
	t_node	*head;
	int		i;
	int		type;
	char	*str;

	i = 0;
	head = NULL;
	while (i < stack_size)
	{
		str = argv[i + 1];
		type = str_type(str);
		if (type == NORMAL_NUM)
			add_to_list(&head, str);
		else if (type == COMPLICATED_INPUT)
			handle_complicated_input(&head, argv, i, str);
		else if (type == INVALID_INPUT)
			return (ft_lstclear_int(head), ft_putendl_fd("Error", 2),
				exit(EXIT_FAILURE), NULL);
		i++;
	}
	return (head);
}
