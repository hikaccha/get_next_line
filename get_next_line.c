/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:37:47 by hichikaw          #+#    #+#             */
/*   Updated: 2025/01/23 13:45:39 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_place(char *temp_buffer, char *buffer, char *temp)
{
	if (temp_buffer)
		free(temp_buffer);
	if (buffer)
		free(buffer);
	if (temp && *temp == '\0')
	{
		free(temp);
		temp = NULL;
		return (temp);
	}
	return (NULL);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	char	*new_buffer;
	ssize_t	bytes_read;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_place(temp_buffer, buffer, NULL));
		if (bytes_read == 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, temp_buffer);
		if (buffer)
			free(buffer);
		buffer = new_buffer;
		if (!buffer)
			return (free_place(temp_buffer, NULL, NULL));
	}
	free(temp_buffer);
	return (buffer);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line = ft_strndup(*buffer, newline_pos - *buffer + 1);
		if (ft_strlen(newline_pos + 1) == 0)
			temp = NULL;
		else
			temp = ft_strdup(newline_pos + 1);
	}
	else
	{
		line = ft_strdup(*buffer);
		temp = NULL;
	}
	free(*buffer);
	free_place(NULL, NULL, temp);
	*buffer = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	return (line);
}
