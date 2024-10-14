/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_validation_bonus2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:42:32 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 21:43:23 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	check_chars(t_map *map, int *err)
{
	int	y;

	y = 0;
	while (y < map->height && !(*err))
	{
		if (map->width != (int)ft_strspn(map->content[y], MAP_CNT_CHARS))
		{
			(*err)++;
			ft_fprintf(2, RED"Invalid char in map:\n"D);
			print_map_error(map, y, ft_strspn(map->content[y], MAP_CNT_CHARS));
		}
		y++;
	}
}

int	has_defined_insides(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->content[y][x] == '0')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	map_validation(t_map *map, int *err)
{
	int	y;
	int	x;

	check_chars(map, err);
	check_spawn(map, err);
	check_doors(map, err);
	while (has_defined_insides(map) && !(*err))
	{
		init_flood(map);
		flood(map);
	}
	y = 0;
	while (y < map->height && !(*err))
	{
		x = 0;
		while (x < map->width && !(*err))
		{
			if (map->content[y][x] == 'X')
				check_the_spot(map, y, x, err);
			x++;
		}
		y++;
	}
}

void	handle_clear_spawn_point(t_map *m, int x, int y)
{
	if (y == m->spawn_y && x == m->spawn_x)
		m->content[y][x] = m->spawn;
}

void	handle_clear_x_content(t_map *m, int x, int y)
{
	if (m->content[y][x] == 'X')
		m->content[y][x] = '0';
}
