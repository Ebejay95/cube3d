/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/03 19:38:24 by ajehle           ###   ########.fr       */
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

float	calculate_len(t_game* game,float x_coordinate,float y_coordinate)
{
	float len_x;
	float len_y;

	len_x = x_coordinate - game->player->x;
	len_y = y_coordinate - game->player->y;
	return(sqrt(pow(len_x, 2) + pow(len_y, 2)));
}



float get_horizontal_len_to_wall(t_game* game, float current_angle)
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


float get_vertical_len_to_wall(t_game* game, float current_angle)
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


void calculate_wall_slice_height(float distance, float *start_height, float *end_height)
{
	float height = 32000 / distance;
	*start_height = (WINDOW_HEIGHT / 2) - height / 2;
	*end_height = (WINDOW_HEIGHT / 2) + height / 2;

}

void draw_wall(mlx_image_t *surface, int x, float start_height, float end_height)
{
	int y = (int)start_height;
	while (y < (int)end_height)
	{
		draw_pixel(surface, x, y, WALL_COLOR2);
		y++;
	}
}

int	render(t_game* game)
{
	// printf("Y:%.2f X:%.2f A:%.2f\n",game->player->y,game->player->x,game->player->angle);
	int	index_of_ray;
	float current_angle;
	float horizontal_line;
	float vertical_line;
	float ray_len;

	float start_height;
	float end_height;

	index_of_ray = 0;
	current_angle = game->player->angle - (FOV / 2);
	while (index_of_ray <= NUM_RAYS)
	{
		normalize_angle(&current_angle);
		horizontal_line = get_horizontal_len_to_wall(game, current_angle);
		vertical_line = get_vertical_len_to_wall(game, current_angle);

		printf("H:%.2f V:%.2f\n",horizontal_line, vertical_line);

		if(vertical_line >= horizontal_line)
			ray_len = vertical_line;
		else
			ray_len = horizontal_line;
		// render_wall(game, ray_len, index_of_ray);
		calculate_wall_slice_height(ray_len, &start_height, &end_height);
		draw_wall(game->surface, index_of_ray, start_height, end_height);

		index_of_ray++;
		current_angle += (FOV / WINDOW_WIDTH);
	}


	return 0;
}
