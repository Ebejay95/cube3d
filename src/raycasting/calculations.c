/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:03:39 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 14:25:36 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*****************************************/
/*	Calculation to get the len of the ray
 	hitting the horizontal grid			 */
/*****************************************/
float get_len_to_horizontal_wall(t_game* game, t_ray* ray)
{
	float	y_coordinate;
	float	x_coordinate;
	float	len_y;
	float	len_x;
	int		direction;

	len_y = CELL;
	len_x = CELL / tan(ray->current_angle);
	y_coordinate = floor(game->player->y / CELL) * CELL;
	direction = get_horizontal_direction(ray->current_angle, &y_coordinate, &len_y);
	x_coordinate = game->player->x + (y_coordinate - game->player->y) / tan(ray->current_angle);
	if (is_looking_west(ray->current_angle) && len_x > 0)
		len_x *= -1;
	if (!is_looking_west(ray->current_angle) && len_x < 0)
		len_x *= -1;
	while (!is_wall(game, x_coordinate, y_coordinate - direction))
	{
		x_coordinate += len_x;
		y_coordinate += len_y;
	}
	ray->wall_hit_x = x_coordinate;
	return calculate_len(game, x_coordinate, y_coordinate);
}


/*****************************************/
/*	Calculation to get the len of the ray
 	hitting the vertical grid				 */
/*****************************************/
float get_len_to_vertical_wall(t_game* game, t_ray* ray)
{
	float	y_coordinate;
	float	x_coordinate;
	float	len_y;
	float	len_x;
	int		direction;

	len_x = CELL;
	len_y = CELL * tan(ray->current_angle);
	x_coordinate = floor(game->player->x / CELL) * CELL;
	direction = get_vertical_direction(ray->current_angle, &x_coordinate, &len_x);
	y_coordinate = game->player->y + (x_coordinate - game->player->x) * tan(ray->current_angle);
	if (is_looking_south(ray->current_angle) && len_y < 0)
		len_y *= -1;
	if(!is_looking_south(ray->current_angle) && len_y > 0)
		len_y *= -1;
	while (!is_wall(game, x_coordinate - direction, y_coordinate))
	{
		x_coordinate += len_x;
		y_coordinate += len_y;
	}
	ray->wall_hit_y = y_coordinate;
	return calculate_len(game, x_coordinate, y_coordinate);
}


int	ray_calculation(t_game* game)
{
	t_ray ray;

	ray.index = 0;
	ray.current_angle = game->player->angle - (FOV_RAD / 2);
	while (ray.index < NUM_RAYS)
	{
		ray.current_angle = angle_check(ray.current_angle);
		ray.horizontal_len = get_len_to_horizontal_wall(game, &ray);
		ray.vertical_len = get_len_to_vertical_wall(game, &ray);
		// ray.horizontal_len = get_len_to_horizontal_wall(game, ray);
		// ray.vertical_len = get_len_to_vertical_wall(game, ray);
		ray.len = get_min(ray.vertical_len, ray.horizontal_len);
		rendering_wall(game, ray);
		ray.index++;
		ray.current_angle += (FOV_RAD / WINDOW_WIDTH);
	}
	return 0;
}
