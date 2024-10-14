/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:01:36 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 17:21:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

static t_hit	cast_horizontal_ray(t_game *game, float angle)
{
	t_hit	hit;
	float	y;
	float	x;
	float	len_y;
	float	len_x;
	int		direction;
	int		map_y;
	int		map_x;
	char	cell;

	hit = (t_hit){INFINITY, 0, 0, 0};
	len_y = CELL;
	len_x = CELL / tan(angle);
	y = floor(game->player->y / CELL) * CELL;
	direction = get_h_drctn(angle, &y, &len_y);
	x = game->player->x + (y - game->player->y) / tan(angle);
	if (is_looking_west(angle) && len_x > 0)
		len_x *= -1;
	if (!is_looking_west(angle) && len_x < 0)
		len_x *= -1;
	while (1)
	{
		map_y = (int)((y - direction) / CELL);
		map_x = (int)(x / CELL);
		if (map_x < 0 || map_y < 0 || map_x >= game->map->width || map_y >= game->map->height)
			break ;
		cell = game->map->content[map_y][map_x];
		if (cell == '1' || ((cell == 'V' || cell == 'H') && !is_door_open(game, map_x, map_y)))
		{
			hit.distance = calculate_len(game, x, y);
			hit.is_door = (cell == 'V' || cell == 'H');
			hit.x = x;
			hit.y = y;
			break ;
		}
		x += len_x;
		y += len_y;
	}
	return (hit);
}

static t_hit	cast_vertical_ray(t_game *game, float angle)
{
	t_hit	hit;
	float	y;
	float	x;
	float	len_y;
	float	len_x;
	int		direction;
	int		map_y;
	int		map_x;
	char	cell;

	hit = (t_hit){INFINITY, 0, 0, 0};
	len_x = CELL;
	len_y = CELL * tan(angle);
	x = floor(game->player->x / CELL) * CELL;
	direction = get_v_drctn(angle, &x, &len_x);
	y = game->player->y + (x - game->player->x) * tan(angle);
	if (is_looking_south(angle) && len_y < 0)
		len_y *= -1;
	if (!is_looking_south(angle) && len_y > 0)
		len_y *= -1;
	while (1)
	{
		map_y = (int)(y / CELL);
		map_x = (int)((x - direction) / CELL);
		if (map_x < 0 || map_y < 0 || map_x >= game->map->width || map_y >= game->map->height)
			break ;
		cell = game->map->content[map_y][map_x];
		if (cell == '1' || ((cell == 'V' || cell == 'H') && !is_door_open(game, map_x, map_y)))
		{
			hit.distance = calculate_len(game, x, y);
			hit.is_door = (cell == 'V' || cell == 'H');
			hit.x = x;
			hit.y = y;
			break ;
		}
		x += len_x;
		y += len_y;
	}
	return (hit);
}

static float	get_len_to_wall(t_game *game, t_ray *ray)
{
	t_hit	h_hit;
	t_hit	v_hit;

	h_hit = cast_horizontal_ray(game, ray->current_angle);
	v_hit = cast_vertical_ray(game, ray->current_angle);
	if (h_hit.distance < v_hit.distance)
	{
		ray->hit_door = h_hit.is_door;
		ray->wall_hit_x = h_hit.x;
		ray->wall_hit_y = h_hit.y;
		ray->horizontal_len = h_hit.distance;
		ray->vertical_len = v_hit.distance;
		return (h_hit.distance);
	}
	else
	{
		ray->hit_door = v_hit.is_door;
		ray->wall_hit_x = v_hit.x;
		ray->wall_hit_y = v_hit.y;
		ray->horizontal_len = h_hit.distance;
		ray->vertical_len = v_hit.distance;
		return (v_hit.distance);
	}
}


int	ray_calculation(t_game *game)
{
	t_ray	ray;

	ray.index = 0;
	ray.current_angle = game->player->angle - (((FOV * PI) / 180) / 2);
	while (ray.index < NUM_RAYS)
	{
		ray.current_angle = angle_check(ray.current_angle);
		ray.hit_door = 0;
		ray.len = get_len_to_wall(game, &ray);
		ray.len *= 0.4;
		rendering_wall(game, ray);
		ray.index++;
		ray.current_angle += (((FOV * PI) / 180) / WINDOW_WIDTH);
	}
	return (0);
}
