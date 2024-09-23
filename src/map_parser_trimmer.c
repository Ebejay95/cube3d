/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_trimmer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:14:44 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/23 16:36:36 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_map_line(const char *line)
{
	int	has_wall;

	has_wall = 0;
	while (*line)
	{
		if (*line == '1')
			has_wall = 1;
		if (ft_strchr(MAP_CNT_CHARS, *line) == NULL)
			return (0);
		line++;
	}
	return (has_wall);
}

void	find_map_bounds(char **splits, int *start, int *end)
{
	int	i;

	*start = -1;
	*end = -1;
	i = 0;
	while (splits[i])
	{
		if (is_map_line(splits[i]))
		{
			if (*start == -1)
				*start = i;
			*end = i;
		}
		else if (*start != -1)
			break ;
		i++;
	}
}

void	trim_line(char *line)
{
	int	start;
	int	end;
	int	len;

	len = ft_strlen(line);
	start = 0;
	while (start < len && line[start] == ' ')
		start++;
	end = len - 1;
	while (end > start && line[end] == ' ')
		end--;
	if (start > 0 || end < len - 1)
	{
		ft_memmove(line, line + start, end - start + 1);
		line[end - start + 1] = '\0';
	}
}

void	trim_map_lines(char **splits, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		trim_line(splits[i]);
		i++;
	}
}

void	free_rect_array(char **rect_array, int num_rows)
{
	int	i;

	if (rect_array == NULL)
		return ;
	i = 0;
	while (i < num_rows)
	{
		free(rect_array[i]);
		i++;
	}
	free(rect_array);
}
