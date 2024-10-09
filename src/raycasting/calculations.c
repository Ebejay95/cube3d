/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:03:39 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/09 18:23:59 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*****************************************/
/*	Calculation to get the len of the ray
	hitting the horizontal grid				*/
/*****************************************/
float	get_len_to_horizontal_wall(t_game *game, t_ray *ray)
{
	float	y;
	float	x;
	float	len_y;
	float	len_x;
	int		direction;

	len_y = CELL;
	len_x = CELL / tan(ray->current_angle);
	y = floor(game->player->y / CELL) * CELL;
	direction = get_h_drctn(ray->current_angle, &y,
			&len_y);
	x = game->player->x + (y - game->player->y)
		/ tan(ray->current_angle);
	if (is_looking_west(ray->current_angle) && len_x > 0)
		len_x *= -1;
	if (!is_looking_west(ray->current_angle) && len_x < 0)
		len_x *= -1;
	while (!is_wall(game, x, y - direction))
	{
		x += len_x;
		y += len_y;
	}
	ray->wall_hit_x = x;
	return (calculate_len(game, x, y));
}

/*****************************************/
/*	Calculation to get the len of the ray
	hitting the vertical grid					*/
/*****************************************/
float	get_len_to_vertical_wall(t_game *game, t_ray *ray)
{
	float	y;
	float	x;
	float	len_y;
	float	len_x;
	int		direction;

	len_x = CELL;
	len_y = CELL * tan(ray->current_angle);
	x = floor(game->player->x / CELL) * CELL;
	direction = get_v_drctn(ray->current_angle, &x,
			&len_x);
	y = game->player->y + (x - game->player->x)
		* tan(ray->current_angle);
	if (is_looking_south(ray->current_angle) && len_y < 0)
		len_y *= -1;
	if (!is_looking_south(ray->current_angle) && len_y > 0)
		len_y *= -1;
	while (!is_wall(game, x - direction, y))
	{
		x += len_x;
		y += len_y;
	}
	ray->wall_hit_y = y;
	return (calculate_len(game, x, y));
}

int	ray_calculation(t_game *game)
{
	t_ray	ray;

	ray.index = 0;
	ray.current_angle = game->player->angle - (((FOV * PI) / 180) / 2);
	while (ray.index < NUM_RAYS)
	{
		ray.current_angle = angle_check(ray.current_angle);
		ray.horizontal_len = get_len_to_horizontal_wall(game, &ray);
		ray.vertical_len = get_len_to_vertical_wall(game, &ray);
		ray.horizontal_len *= 0.5;
		ray.vertical_len *= 0.5;
		ray.len = get_min(ray.vertical_len, ray.horizontal_len);
		rendering_wall(game, ray);
		ray.index++;
		ray.current_angle += (((FOV * PI) / 180) / WINDOW_WIDTH);
	}
	return (0);
}
