/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:24:34 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/26 17:17:52 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float calculate_distance(float player_x, float player_y, int hitx, int hity, float ray_angle)
{
	float lenx = hitx - player_x;
	float leny = hity - player_y;
	float distance = sqrt((pow(fabs(lenx), 2)) + (pow(fabs(leny), 2)));

	// Correct for the fisheye effect by adjusting the distance with the ray angle
	return fabs(distance * cos(to_radian(180 - ray_angle)));
}

void calculate_wall_slice_height(float distance, float *start_height, float *end_height)
{
	// float height = BLOCK_HEIGHT / distance;
	// *start_height = (WINDOW_HEIGHT / 2) - height / 2;
	// *end_height = (WINDOW_HEIGHT / 2) + height / 2;
	*start_height = WINDOW_HEIGHT / 2 - BLOCK_HEIGHT / distance;
	*end_height = WINDOW_HEIGHT / 2 + BLOCK_HEIGHT / distance;
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

void	render_wall_slice(t_game *game, int hitx, int hity, float ray_angle, int x)
{
	float distance;
	float start_height;
	float end_height;

	distance = calculate_distance(game->player->x, game->player->y, hitx, hity, ray_angle);
	calculate_wall_slice_height(distance, &start_height, &end_height);
	draw_wall(game->surface, x, start_height, end_height);
}

int	render_game(t_game *game)
{
	float	start_angle;
	float	current_angle;
	int		ray_index;
	int		hitx;
	int		hity;

	ray_index = 0;
	start_angle = game->player->angle - (FOV / 2);
	float	angle_begin = -45.0;
	while (ray_index <= NUM_RAYS)
	{
		current_angle = start_angle + ray_index * RAY_ANGLE_STEP;
		current_angle = angle_check(current_angle);

		cast_ray(game, &hitx, &hity, current_angle);
		angle_begin += (90.0f / (float)NUM_RAYS);
		render_wall_slice(game, hitx, hity, angle_begin, ray_index);
		ray_index++;
	}
	return (0);
}
