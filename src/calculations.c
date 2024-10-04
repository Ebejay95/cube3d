/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:03:39 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/04 11:37:46 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	float	len_horizontal = 0;
	int		direction;


	len_y = CELL / tan(current_angle);
	len_x = CELL;
	y_coordinate = fabsf(game->player->y / CELL) * CELL;
	direction = get_horizontal_direction(current_angle, &y_coordinate, &len_y);
	x_coordinate = game->player->x + (y_coordinate - game->player->y) / tan(current_angle);
	if ((is_player_looking_up(current_angle) && len_x > 0) || (is_player_looking_down(current_angle) && len_x < 0))
		len_x *= (-1);
	while (!is_wall(game, x_coordinate, y_coordinate - direction))
	{
		x_coordinate += len_x;
		y_coordinate += len_y;
	}
	len_horizontal = calculate_len(game, x_coordinate, y_coordinate);
	// printf("Y:%.2f X:%.2f LEN:%2.f \n", y_coordinate, x_coordinate, len_horizontal);
	return len_horizontal;
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
	float	len_horizontal = 0;
	int		direction;


	len_y = CELL;
	len_x = CELL / tan(current_angle);
	x_coordinate = fabsf(game->player->x / CELL) * CELL;
	direction = get_vertical_direction(current_angle, &x_coordinate, &len_x);
	y_coordinate = game->player->y + (x_coordinate - game->player->x) / tan(current_angle);
	if ((is_player_looking_down(current_angle) && len_y < 0) || (is_player_looking_up(current_angle) && len_y > 0))
		len_x *= (-1);
	while (!is_wall(game, x_coordinate - direction, y_coordinate))
	{
		x_coordinate += len_x;
		y_coordinate += len_y;
	}
	len_horizontal = calculate_len(game, x_coordinate, y_coordinate);
	// printf("Y:%.2f X:%.2f LEN:%2.f \n", y_coordinate, x_coordinate, len_horizontal);
	return len_horizontal;
}



int	ray_calculation(t_game* game)
{
	// printf("Y:%.2f X:%.2f A:%.2f\n",game->player->y,game->player->x,game->player->angle);
	int	index_of_ray;
	float current_angle;
	float horizontal_line;
	float vertical_line;
	float ray_len;


	index_of_ray = 0;
	current_angle = game->player->angle - (FOV / 2);
	while (index_of_ray <= NUM_RAYS)
	{
		current_angle = angle_check(current_angle);
		horizontal_line = get_len_to_horizontal_wall(game, current_angle);
		vertical_line = get_len_to_vertical_wall(game, current_angle);

/******************************************************************************/
		printf("H:%.2f V:%.2f\n",horizontal_line, vertical_line);

		if(vertical_line >= horizontal_line)
			ray_len = vertical_line;
		else
			ray_len = horizontal_line;
/******************************************************************************/
		// render_wall(game, ray_len, index_of_ray);
		rendering_wall(game, ray_len, index_of_ray, current_angle);
/******************************************************************************/
		index_of_ray++;
		current_angle += (FOV / WINDOW_WIDTH);
	}
	return 0;
}
