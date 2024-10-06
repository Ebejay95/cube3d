/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/06 12:39:19 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void draw_ceiling(mlx_image_t *surface,int index_of_ray ,int top)
{
	while (top)
	{
		draw_pixel(surface, index_of_ray, top, WALL_COLOR3);
		top--;
	}
}

void draw_floor(mlx_image_t *surface,int index_of_ray ,int bottom)
{
	while (bottom < WINDOW_HEIGHT)
	{
		draw_pixel(surface, index_of_ray, bottom, WALL_COLOR3);
		bottom++;
	}
}

void draw_wall(mlx_image_t *surface,int index_of_ray ,int top, int bottom)
{

	while (top < bottom)
	{
			draw_pixel(surface, index_of_ray, top, WALL_COLOR2);
		top++;
	}
}

void	rendering_wall(t_game* game, float ray_len, int index_of_ray, float current_angle)
{
	float bottom;
	float top;
	float wall_height;

	ray_len = fish_eye_correction(game, ray_len, current_angle);
	wall_height = (CELL / ray_len) * ((WINDOW_HEIGHT/2) / tan(FOV / 2));
	calculate_wall_slice_height(wall_height, &top, &bottom);
	draw_ceiling(game->surface, index_of_ray, top);
	draw_floor(game->surface, index_of_ray, bottom);
	draw_wall(game->surface, index_of_ray, top, bottom);
}
