/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_flood_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:07:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:07:44 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	init_flood(t_map *map)
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
				map->content[y][x] = 'X';
			x++;
		}
		y++;
	}
}

void	flood_one(char *ref, int *check, char *work)
{
	if (ft_strchr(ref, *work))
	{
		*work = 'X';
		(*check)--;
	}
}

int	check_xy_nexts(t_map *map, int ydex, int xdex)
{
	int		check;
	char	*ref;

	check = 0;
	ref = ft_strdup("0 ");
	if (ydex != 0)
		flood_one(ref, &check, &map->content[ydex - 1][xdex]);
	if (xdex != 0)
		flood_one(ref, &check, &map->content[ydex][xdex - 1]);
	if (ydex != (map->height - 1))
		flood_one(ref, &check, &map->content[ydex + 1][xdex]);
	if (xdex != (map->width - 1))
		flood_one(ref, &check, &map->content[ydex][xdex + 1]);
	free(ref);
	return (check);
}

void	flood(t_map *map)
{
	int		check;
	int		xdex;
	int		ydex;

	check = -1;
	while (check < 0)
	{
		check = 0;
		ydex = 0;
		while (ydex < map->height)
		{
			xdex = 0;
			while (xdex < map->width)
			{
				if ('X' == map->content[ydex][xdex])
					check = check + check_xy_nexts(map, ydex, xdex);
				xdex++;
			}
			ydex++;
		}
	}
}
