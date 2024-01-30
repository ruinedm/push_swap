/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:06:24 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 02:48:28 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_checker.h"

static char	*append_buffer(char **ptr_to_save, char *buffer, int bytes_read)
{
	char	*temp;

	if (bytes_read == -1)
	{
		free(buffer);
		free(*ptr_to_save);
		*ptr_to_save = NULL;
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	temp = *ptr_to_save;
	*ptr_to_save = ft_strjoin(*ptr_to_save, buffer);
	free(temp);
	if (!*ptr_to_save)
		return (NULL);
	return (*ptr_to_save);
}

static char	*read_and_append(int fd, char **ptr_to_save)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(*ptr_to_save, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		*ptr_to_save = append_buffer(ptr_to_save, buffer, bytes_read);
		if (!*ptr_to_save)
			return (NULL);
	}
	free(buffer);
	if (bytes_read == 0 && *ptr_to_save && (*ptr_to_save)[0] == '\0')
	{
		free(*ptr_to_save);
		*ptr_to_save = NULL;
	}
	return (*ptr_to_save);
}

static char	*extract_line(char **ptr_to_save)
{
	char	*line;
	char	*temp;
	char	*newline;

	newline = ft_strchr(*ptr_to_save, '\n');
	if (newline)
	{
		line = ft_substr(*ptr_to_save, 0, newline - *ptr_to_save + 1);
		temp = *ptr_to_save;
		*ptr_to_save = ft_strdup(newline + 1);
		free(temp);
		if (!*ptr_to_save)
			return (NULL);
	}
	else
	{
		line = ft_strdup(*ptr_to_save);
		free(*ptr_to_save);
		*ptr_to_save = NULL;
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_append(fd, &save);
	if (!save)
		return (NULL);
	line = extract_line(&save);
	return (line);
}
