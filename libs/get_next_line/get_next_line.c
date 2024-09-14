/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:44:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/09 17:31:44 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *static_buf)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (static_buf[i] != '\0' && static_buf[i] != '\n')
		i++;
	if (!static_buf[i])
		return (free(static_buf), NULL);
	while (static_buf[j] != 0)
		j++;
	remain = (char *)gnl_calloc(sizeof(char), (j - i + 1));
	j = 0;
	if (!remain)
		return (NULL);
	i++;
	while (static_buf[i])
	{
		remain[j] = static_buf[i];
		j++;
		i++;
	}
	free(static_buf);
	return (remain);
}

char	*ft_get_line(char *static_buf)
{
	char	*new_line;
	int		i;
	int		extra;

	i = 0;
	extra = 1;
	if (!static_buf[0])
		return (NULL);
	while (static_buf[i] != '\0' && static_buf[i] != '\n')
		i++;
	if (static_buf[i] == '\n')
		extra = 2;
	new_line = gnl_calloc(sizeof(char), (i + extra));
	if (!new_line)
		return (free(static_buf), NULL);
	i = 0;
	while (static_buf[i] != '\0' && static_buf[i] != '\n')
	{
		new_line[i] = static_buf[i];
		i++;
	}
	if (static_buf[i] && static_buf[i] == '\n')
		new_line[i] = '\n';
	return (new_line);
}

char	*ft_helper(char *static_buf, char *temp)
{
	temp = ft_strjoin(static_buf, temp);
	free(static_buf);
	return (temp);
}

char	*read_buffer(int fd, char *static_buf)
{
	char		*temp_buf;
	int			bytes_rd;

	bytes_rd = 1;
	temp_buf = gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp_buf)
	{
		free(static_buf);
		return (NULL);
	}
	while (bytes_rd != 0)
	{
		bytes_rd = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(temp_buf);
			return (NULL);
		}
		temp_buf[bytes_rd] = '\0';
		static_buf = ft_helper(static_buf, temp_buf);
		if (ft_strchr(static_buf, '\n'))
			break ;
	}
	free(temp_buf);
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (static_buf)
		{
			free(static_buf);
			static_buf = NULL;
		}
		return (NULL);
	}
	if (!static_buf)
	{
		static_buf = ft_strdup("");
		if (!static_buf)
			return (NULL);
	}
	static_buf = read_buffer(fd, static_buf);
	if (!static_buf)
		return (NULL);
	line = ft_get_line(static_buf);
	static_buf = ft_next_line(static_buf);
	return (line);
}
