/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_trimmer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:04:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:04:36 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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
