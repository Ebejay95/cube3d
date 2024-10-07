/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 15:33:51 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_game *game, int index_of_ray, int top)
{
	while (top)
	{
		draw_pixel(game->surface, index_of_ray, top, game->map->ceiling);
		top--;
	}
}

void	draw_floor(t_game *game, int index_of_ray, int bottom)
{
	while (bottom < WINDOW_HEIGHT)
	{
		draw_pixel(game->surface, index_of_ray, bottom, game->map->floor);
		bottom++;
	}
}

void	rendering_wall(t_game *game, t_ray ray)
{
	float	bottom;
	float	top;
	float	wall_height;

	ray.len = fish_eye_correction(game, ray.len, ray.current_angle);
	wall_height = (CELL / ray.len) * ((WINDOW_HEIGHT / 2) / tan(M_PI_2 / 2));
	calculate_wall_slice_height(wall_height, &top, &bottom);
	draw_ceiling(game, ray.index, top);
	draw_floor(game, ray.index, bottom);
	draw_wall(game, ray, top, bottom);
}
