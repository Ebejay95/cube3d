/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/06 17:09:09 by ajehle           ###   ########.fr       */
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
		draw_pixel(surface, index_of_ray, bottom, WALL_COLOR2);
		bottom++;
	}
}

void draw_wall(t_game* game, mlx_image_t *surface,int index_of_ray ,int top, int bottom)
{
	unsigned int	i;
	uint32_t color;

	i = 0;
	if(index_of_ray % 4 == 0)
		i = 0;
	else if(index_of_ray % 4 == 1)
		i = game->map->tex_north->height + 1;
	else if(index_of_ray % 4 == 2)
		i = game->map->tex_north->height * 2 + 1;
	else if(index_of_ray % 4 == 3)
		i = game->map->tex_north->height * 3 + 1;

	while (top < bottom)
	{
		color = get_rgba_colors_hex(game->map->tex_north->pixels[i],game->map->tex_north->pixels[i + 1],game->map->tex_north->pixels[i + 2],game->map->tex_north->pixels[i+3]);
		draw_pixel(surface, index_of_ray, top, color);
		top++;
		i += 4;
		if(i > (game->map->tex_north->height * game->map->tex_north->bytes_per_pixel)) // >= ?
			i = 0;
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
	draw_wall(game, game->surface, index_of_ray, top, bottom);
}
