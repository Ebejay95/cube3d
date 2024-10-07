/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 12:58:01 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(mlx_image_t *surface,int index_of_ray ,int top)
{
	while (top)
	{
		draw_pixel(surface, index_of_ray, top, WALL_COLOR3);
		top--;
	}
}

void	draw_floor(mlx_image_t *surface,int index_of_ray ,int bottom)
{
	while (bottom < WINDOW_HEIGHT)
	{
		draw_pixel(surface, index_of_ray, bottom, WALL_COLOR2);
		bottom++;
	}
}

void	rendering_wall(t_game* game, t_ray ray)
{
	float bottom;
	float top;
	float wall_height;

	ray.len = fish_eye_correction(game, ray.len, ray.current_angle);
	wall_height = (CELL / ray.len) * ((WINDOW_HEIGHT/2) / tan(M_PI_2 / 2));
	calculate_wall_slice_height(wall_height, &top, &bottom);
	draw_ceiling(game->surface, ray.index, top);
	draw_floor(game->surface, ray.index, bottom);
	draw_wall(game, ray, top, bottom);
}
