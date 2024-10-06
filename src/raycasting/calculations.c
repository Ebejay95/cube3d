/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:03:39 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/06 15:31:54 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*****************************************/
/*	Calculation to get the len of the ray
 	hitting the horizontal grid			 */
/*****************************************/
float get_len_to_horizontal_wall(t_game* game, float current_angle)
{
	float	y_coordinate;
	float	x_coordinate;
	float	len_y;
	float	len_x;
	int		direction;

	len_y = CELL;
	len_x = CELL / tan(current_angle);
	y_coordinate = floor(game->player->y / CELL) * CELL;
	direction = get_horizontal_direction(current_angle, &y_coordinate, &len_y);
	x_coordinate = game->player->x + (y_coordinate - game->player->y) / tan(current_angle);
	if (is_looking_west(current_angle) && len_x > 0)
		len_x *= -1;
	if (!is_looking_west(current_angle) && len_x < 0)
		len_x *= -1;
	while (!is_wall(game, x_coordinate, y_coordinate - direction))
	{
		x_coordinate += len_x;
		y_coordinate += len_y;
	}
	return calculate_len(game, x_coordinate, y_coordinate);
}


/*****************************************/
/*	Calculation to get the len of the ray
 	hitting the vertical grid				 */
/*****************************************/
float get_len_to_vertical_wall(t_game* game, float current_angle)
{
	float	y_coordinate;
	float	x_coordinate;
	float	len_y;
	float	len_x;
	int		direction;

	len_x = CELL;
	len_y = CELL * tan(current_angle);
	x_coordinate = floor(game->player->x / CELL) * CELL;
	direction = get_vertical_direction(current_angle, &x_coordinate, &len_x);
	y_coordinate = game->player->y + (x_coordinate - game->player->x) * tan(current_angle);
	if (is_looking_south(current_angle) && len_y < 0)
		len_y *= -1;
	if(!is_looking_south(current_angle) && len_y > 0)
		len_y *= -1;
	while (!is_wall(game, x_coordinate - direction, y_coordinate))
	{
		x_coordinate += len_x;
		y_coordinate += len_y;
	}
	return calculate_len(game, x_coordinate, y_coordinate);
}


int	ray_calculation(t_game* game)
{
	int	index_of_ray;
	float current_angle;
	float horizontal_line;
	float vertical_line;

	index_of_ray = 0;

	// doesnt work with the calculation?!?!?!?!
	// current_angle = game->player->angle - (((FOV * M_PI) / 180) / 2);
	current_angle = game->player->angle - 0.52;

	while (index_of_ray < NUM_RAYS)
	{
		current_angle = angle_check(current_angle);
		horizontal_line = get_len_to_horizontal_wall(game, current_angle);
		vertical_line = get_len_to_vertical_wall(game, current_angle);
		rendering_wall(game, vertical_line, horizontal_line, index_of_ray, current_angle);
		index_of_ray++;

	// doesnt work with the calculation?!?!?!?!
		// current_angle += ((FOV) / WINDOW_WIDTH);
		current_angle += (1.05 / WINDOW_WIDTH);
	}
	return 0;
}
