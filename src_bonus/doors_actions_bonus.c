/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:24:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/17 14:49:49 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

int	is_ray_out_of_bounds(t_game *game, t_dctx *ray)
{
	return (ray->map_x < 0 || ray->map_y < 0
		|| ray->map_x >= game->map->width || ray->map_y >= game->map->height);
}

void	cast_dctx(t_game *game, t_dctx *ray, t_door_finder *df)
{
	init_ray(game, ray);
	while (1)
	{
		update_ray_position(ray);
		if (is_ray_out_of_bounds(game, ray))
			break ;
		ray->cell = game->map->content[ray->map_y][ray->map_x];
		if (ray->cell == 'V' || ray->cell == 'H')
		{
			ray->distance = sqrt(pow(ray->x - game->player->x, 2)
					+ pow(ray->y - game->player->y, 2));
			if (ray->distance < df->min_distance)
			{
				df->min_distance = ray->distance;
				df->door_x = ray->x;
				df->door_y = ray->y;
				df->found = 1;
			}
			break ;
		}
		if (ray->cell == '1')
			break ;
	}
}

float	find_nearest_door(t_game *game, float *door_x, float *door_y)
{
	float			start_angle;
	t_door_finder	df;
	t_dctx			ray;
	int				i;

	start_angle = game->player->angle - (FOV * PI / 180) / 2;
	df.min_distance = INFINITY;
	df.found = 0;
	i = 0;
	while (i < NUM_RAYS)
	{
		ray.angle = angle_check(start_angle + i * (FOV * PI / 180) / NUM_RAYS);
		cast_dctx(game, &ray, &df);
		i++;
	}
	*door_x = df.door_x;
	*door_y = df.door_y;
	if (df.found)
		return (df.min_distance);
	return (-1);
}

void	update_door_on_map(t_game *game, t_door *door, int map_x, int map_y)
{
	char	open_symbol;
	char	closed_symbol;

	if (door->direction == 'v')
	{
		open_symbol = 'V';
		closed_symbol = 'H';
	}
	else
	{
		open_symbol = 'H';
		closed_symbol = 'V';
	}
	if (door->open)
		game->map->content[map_y][map_x] = open_symbol;
	else
		game->map->content[map_y][map_x] = closed_symbol;
}

void	toggle_door(t_game *game, int map_x, int map_y)
{
	t_door	*door;
	int		player_cell_x;
	int		player_cell_y;

	door = get_door(game->map, map_x, map_y);
	if (door)
	{
		player_cell_x = game->player->x / CELL;
		player_cell_y = game->player->y / CELL;
		if (player_cell_x == map_x && player_cell_y == map_y)
			return ;
		door->open = !door->open;
		update_door_on_map(game, door, map_x, map_y);
	}
}
