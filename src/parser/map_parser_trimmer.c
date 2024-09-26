/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_trimmer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:14:44 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/26 11:14:43 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_map_line(char *line)
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
