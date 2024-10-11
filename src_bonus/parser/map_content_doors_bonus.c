/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_doors_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:36:40 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/11 15:19:21 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	get_door_direction(t_map *m, int x, int y, char *dir)
{
	char	**c;
	int		w;

	w = m->width;
	c = m->content;
	*dir = '-';
	if (y != 0 && y != (m->height - 1))
	{
		if (c[y - 1][x] == '1' && c[y + 1][x] == '1' && x != 0 && x != (w - 1))
		{
			if (c[y][x - 1] != '1' && c[y][x + 1] != '1')
				*dir = 'v';
		}
	}
	if (x != 0 && x != (w - 1) && *dir == '-')
	{
		if (c[y][x - 1] == '1' && c[y][x + 1] == '1' && y != 0 && y != (w - 1))
		{
			if (c[y - 1][x] != '1' && c[y + 1][x] != '1')
				*dir = 'h';
		}
	}
	m->content[y][x] = '0';
}

void	add_door(t_map *map, int x, int y, int *err)
{
	t_door	*new_door;

	if (map->door_count >= (MAX_DOORS - 1))
	{
		(*err)++;
		ft_fprintf(2, RED"Maximum number of doors reached\n"D);
		return ;
	}
	new_door = malloc(sizeof(t_door));
	if (!new_door)
	{
		(*err)++;
		ft_fprintf(2, RED"Door allocation failed\n"D);
		return ;
	}
	new_door->x = x;
	new_door->y = y;
	new_door->open = 0;
	get_door_direction(map, x, y, &(new_door->direction));
	map->doors[map->door_count] = new_door;
	map->door_count++;
	map->doors[map->door_count] = NULL;
}

void	check_door_cell(t_map *map, int y, int x, int *err)
{
	if (map->content[y][x] == 'D')
		add_door(map, x, y, err);
}

void	check_doors(t_map *map, int *err)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			check_door_cell(map, y, x, err);
			x++;
		}
		y++;
	}
}

t_door	*get_door(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->door_count)
	{
		if (x == map->doors[i]->x && y == map->doors[i]->y)
			return (map->doors[i]);
		i++;
	}
	return (NULL);
}
