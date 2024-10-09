/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_spawn_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:07:22 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:07:30 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	set_spawn_point(t_map *map, int x, int y)
{
	map->spawn = map->content[y][x];
	map->spawn_x = x;
	map->spawn_y = y;
	map->content[y][x] = '0';
}

void	handle_multiple_spawns(t_map *map, int y, int x, int *err)
{
	(*err)++;
	ft_fprintf(2, RED"multiple spawns detected:\n"D);
	print_map_error(map, y, x);
}

void	check_spawn_cell(t_map *map, int y, int x, int *err)
{
	if (ft_strchr("NEWS", map->content[y][x]) != NULL)
	{
		if (map->spawn == '-')
			set_spawn_point(map, x, y);
		else
			handle_multiple_spawns(map, y, x, err);
	}
}

void	handle_no_spawns(t_map *map, int *err)
{
	(*err)++;
	ft_fprintf(2, RED"no spawns detected:\n"D);
	print_map_error(map, 0, 0);
}

void	check_spawn(t_map *map, int *err)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height && !(*err))
	{
		x = 0;
		while (x < map->width)
		{
			check_spawn_cell(map, y, x, err);
			x++;
		}
		y++;
	}
	if (map->spawn == '-' && !(*err))
		handle_no_spawns(map, err);
}
