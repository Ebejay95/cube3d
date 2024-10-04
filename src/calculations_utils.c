/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:04:04 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/04 14:09:17 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	is_player_looking_up(float angle)
{
	if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
		return (1);
	return(0);
}

int	is_player_looking_down(float angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	return(0);
}


int	is_position_in_map(t_game* game,int pos_x,int pos_y)
{
	if(game->map->content[pos_y] && pos_x <= (int)ft_strlen(game->map->content[pos_y]))
			return(1);
	return(0);
}

int	is_wall(t_game* game,float x_coordinate,float y_coordinate)
{
	int	y;
	int	x;

	y = floor(y_coordinate / CELL);
	x = floor(x_coordinate / CELL);
	// printf("Y:[%i] X:[%i] \n", y, x);

	if(y >= game->map->height || y < 0)
		return(1);
	if(x >= game->map->width || x < 0)
		return(1);
	if(is_position_in_map(game, y, x))
		if(game->map->content[y][x] == '1')
			return(1);
	return(0);

}


// if the player is looking downwards the next tile size is added???
// if the player ???
int get_horizontal_direction(float current_angle,float* y_coordinate,float* len_y)
{
	if(is_player_looking_down(current_angle))
	{
		*y_coordinate = *y_coordinate + CELL;
		return(-1);
	}
	*len_y = *len_y * (-1);
	return(1);
}

int get_vertical_direction(float current_angle,float* x_coordinate,float* len_x)
{
	if(is_player_looking_up(current_angle))
	{
		*x_coordinate = *x_coordinate + CELL;
		return(-1);
	}
	*len_x = *len_x * (-1);
	return(1);
}


float	calculate_len(t_game* game, float x_coordinate, float y_coordinate)
{
	float len_x;
	float len_y;

	// printf("%.2f	%.2f %.2f %.2f\n", game->player->x, game->player->y, x_coordinate, y_coordinate);
	len_x = x_coordinate - game->player->x;
	len_y = y_coordinate - game->player->y;
	return(sqrt(pow(len_x, 2) + pow(len_y, 2)));
}
