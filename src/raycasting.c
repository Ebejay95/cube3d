/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:24:34 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/04 12:02:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float calculate_distance(float player_x, float player_y, int hitx, int hity, float ray_angle)
{
	float horizontal;
	float vertical;
	float distance;

	horizontal = fabs(hitx - player_x);
	vertical = fabs(hity - player_y);
	printf("H %f V %f\n", horizontal, vertical);
	distance = sqrt((pow(horizontal, 2)) + (pow(vertical, 2)));
	// Correct for the fisheye effect by adjusting the distance with the ray angle
	return (distance * cos(to_radian(ray_angle)));
	// return (distance * cos(to_radian(180 - ray_angle)));
	// return fabs(distance * cos(to_radian(180 - ray_angle)));
}

// void calculate_wall_slice_height(float distance, float *start_height, float *end_height)
// {
// 	// float height = CELL / distance;
// 	float height = 32000 / distance;
// 	*start_height = (WINDOW_HEIGHT / 2) - height / 2;
// 	*end_height = (WINDOW_HEIGHT / 2) + height / 2;
// // 	*start_height = WINDOW_HEIGHT / 2 - BLOCK_HEIGHT / distance;
// // 	*end_height = WINDOW_HEIGHT / 2 + BLOCK_HEIGHT / distance;
// }

// void draw_wall(mlx_image_t *surface, int x, float start_height, float end_height)
// {
// 	int y = (int)start_height;
// 	while (y < (int)end_height)
// 	{
// 		draw_pixel(surface, x, y, WALL_COLOR2);
// 		y++;
// 	}
// }

void	render_wall_slice(t_game *game, int hitx, int hity, float ray_angle, int x)
{
// 	float distance;
// 	float start_height;
// 	float end_height;

// 	distance = calculate_distance(game->player->x, game->player->y, hitx, hity, ray_angle);
// 	// distance = distance * cos(game->player->angle - ray_angle); //Fisheye correciton!!!!!!!

// 	calculate_wall_slice_height(distance, &start_height, &end_height);
// 	// if(x % 8)
// 		draw_wall(game->surface, x, start_height, end_height);
// 	// else
// 		// draw_wall2(game->surface, x, start_height, end_height);
}





int	render_game(t_game *game)
{
	float	start_angle;
	float	current_angle;
	int		ray_index;
	int		hitx;
	int		hity;
	// float distance;

	// distance = 0;
	ray_index = 0;
	// start_angle = game->player->angle - (float)(FOV / 2);
	// float	angle_begin = -45.0;
	while (ray_index <= NUM_RAYS)
	{
		start_angle = ray_index - (float)(FOV / 2);
		// current_angle = angle_check(start_angle + ray_index * RAY_ANGLE_STEP);
		// current_angle = angle_check(start_angle + ray_index * ((float)FOV / (float)NUM_RAYS));
		current_angle = game->player->angle + atan(start_angle / NUM_RAYS * tan(FOV / 1.1));
		current_angle = angle_check(current_angle);
		cast_ray(game, &hitx, &hity, current_angle);
		// angle_begin += (90.0f / (float)NUM_RAYS);
		render_wall_slice(game, hitx, hity, current_angle, ray_index);
		ray_index++;
	}
	return (0);
}
