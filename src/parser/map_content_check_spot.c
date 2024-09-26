/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_check_spot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:28:00 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/26 11:14:24 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_the_spot_down(t_map *map, int ydex, int xdex, int *err)
{
	int	y;

	y = ydex;
	while (y < map->height)
	{
		if (map->content[y][xdex] == '1')
			return ;
		y++;
	}
	(*err)++;
	ft_fprintf(2, RED"The map content is not closed - detected here:\n"D);
	print_map_error(map, ydex, xdex);
}

void	check_the_spot_up(t_map *map, int ydex, int xdex, int *err)
{
	int	y;

	y = ydex;
	while (y >= 0)
	{
		if (map->content[y][xdex] == '1')
			return ;
		y--;
	}
	(*err)++;
	ft_fprintf(2, RED"The map content is not closed - detected here:\n"D);
	print_map_error(map, ydex, xdex);
}

void	check_the_spot_left(t_map *map, int ydex, int xdex, int *err)
{
	int	x;

	x = xdex;
	while (x >= 0)
	{
		if (map->content[ydex][x] == '1')
			return ;
		x--;
	}
	(*err)++;
	ft_fprintf(2, RED"The map content is not closed - detected here:\n"D);
	print_map_error(map, ydex, xdex);
}

void	check_the_spot_right(t_map *map, int ydex, int xdex, int *err)
{
	int	x;

	x = xdex;
	while (x < map->width)
	{
		if (map->content[ydex][x] == '1')
			return ;
		x++;
	}
	(*err)++;
	ft_fprintf(2, RED"The map content is not closed - detected here:\n"D);
	print_map_error(map, ydex, xdex);
}

void	check_the_spot(t_map *map, int ydex, int xdex, int *err)
{
	if (!(*err))
		check_the_spot_up(map, ydex, xdex, err);
	if (!(*err))
		check_the_spot_down(map, ydex, xdex, err);
	if (!(*err))
		check_the_spot_left(map, ydex, xdex, err);
	if (!(*err))
		check_the_spot_right(map, ydex, xdex, err);
}
