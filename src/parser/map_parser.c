/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:50:56 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/08 17:44:54 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	trim_map_content(char **splits, t_map_bounds *bounds)
{
	int		i;
	char	*new_line;

	i = bounds->start;
	while (i <= bounds->end)
	{
		new_line = create_new_line(splits[i], bounds);
		if (!new_line)
			return ;
		free(splits[i]);
		splits[i] = new_line;
		i++;
	}
}

int	allocate_map_content(t_map *map)
{
	map->content = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->content)
		return (0);
	return (1);
}

int	copy_map_content_process(t_map *map, char **splits, int start, int i)
{
	map->content[i] = ft_strdup(splits[start + i]);
	if (!map->content[i])
	{
		while (i > 0)
			free(map->content[--i]);
		free(map->content);
		map->content = NULL;
		return (0);
	}
	return (1);
}

int	copy_map_content(t_map *map, char **splits, int start)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (!copy_map_content_process(map, splits, start, i))
			return (0);
		i++;
	}
	map->content[map->height] = NULL;
	return (1);
}

void	parse_map_array(t_map *map, char **splits)
{
	t_map_bounds	bounds;

	find_map_bounds(splits, &bounds.start, &bounds.end);
	if (bounds.start == -1 || bounds.end == -1)
	{
		free_splits(splits);
		return ;
	}
	find_map_width(splits, &bounds);
	trim_map_content(splits, &bounds);
	map->height = bounds.end - bounds.start + 1;
	map->width = bounds.right - bounds.left + 1;
	if (!allocate_map_content(map))
	{
		free_splits(splits);
		return ;
	}
	if (!copy_map_content(map, splits, bounds.start))
	{
		free_splits(splits);
		return ;
	}
	free_splits(splits);
}
