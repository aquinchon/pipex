/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:24:59 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/19 10:25:34 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cpybuffer(char *buffer, char *buf_read)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf_read);
	free(buffer);
	return (temp);
}

char	*ft_cutline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_resize_buffer(char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer [i])
	{
		tmp[j] = buffer[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	char	*buf_read;
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	buf_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0 && (buffer && !ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buf_read, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf_read);
			free(buffer);
			return (NULL);
		}
		buf_read[bytes_read] = '\0';
		buffer = ft_cpybuffer(buffer, buf_read);
	}
	free(buf_read);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_cutline(buffer);
	buffer = ft_resize_buffer(buffer);
	return (line);
}
