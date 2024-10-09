/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_meta_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:42 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/09 15:52:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*get_textr_path(char *line, size_t size, int *err)
{
	size_t	i;
	size_t	j;
	size_t	new_size;
	char	*path;

	i = 0;
	while (line[i] && i < size)
		i++;
	if (i < size)
		(*err)++;
	new_size = i;
	while (line[new_size] && line[new_size] != '\n')
		new_size++;
	new_size = new_size - i;
	path = malloc(sizeof(char) * (new_size + 1));
	if (!path)
		return ((*err)++, NULL);
	j = 0;
	while (j < new_size)
	{
		path[j] = line[j + i];
		j++;
	}
	path[new_size] = '\0';
	return (path);
}

char	*trim_whitespace_and_newline(char *str)
{
	char	*end;

	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;
	*(end + 1) = '\0';
	return (str);
}

uint32_t	create_color(int r, int g, int b)
{
	return (0xFF | (b << 8) | (g << 16) | (r << 24));
}

int	validate_color_component(char *component)
{
	int	i;
	int	value;

	i = 0;
	while (component[i])
	{
		if (!ft_isdigit(component[i]))
			return (0);
		i++;
	}
	value = ft_atoi(component);
	if (value < 0 || value > 255)
		return (0);
	return (1);
}

int	validate_color_split(char **split)
{
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		return (0);
	}
	if (!validate_color_component(split[0])
		|| !validate_color_component(split[1])
		|| !validate_color_component(split[2]))
	{
		return (0);
	}
	return (1);
}
