/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/09 22:36:21 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_game *game, int index_of_ray, int top)
{
	while (top)
	{
		drawpixel(game->surface, index_of_ray, top, game->map->ceiling);
		top--;
	}
}

void	draw_floor(t_game *game, int index_of_ray, int bottom)
{
	while (bottom < WINDOW_HEIGHT)
	{
		drawpixel(game->surface, index_of_ray, bottom, game->map->floor);
		bottom++;
	}
}

void	rendering_wall(t_game *game, t_ray ray)
{
	float	fcbottom;
	float	fctop;
	float	bottom;
	float	top;
	float	wall_height;

	ray.len = fish_eye_crct(game, ray.len, ray.current_angle);
	wall_height = (CELL / ray.len) * ((WINDOW_HEIGHT / 2) / tan(M_PI_2 / 2));
	top = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	bottom = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	fctop = top;
	fcbottom = bottom;
	calc_wallslice_height(&fctop, &fcbottom);
	draw_ceiling(game, ray.index, fctop);
	draw_floor(game, ray.index, fcbottom);
	draw_wall(game, ray, top, bottom);
}
