/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:12:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/17 17:12:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

char	get_shade(t_ray ray)
{
	if (ray.verlen <= ray.horlen)
	{
		if (is_looking_west(ray.current_angle))
			return ('w');
		else
			return ('e');
	}
	else
	{
		if (is_looking_south(ray.current_angle))
			return ('s');
		else
			return ('n');
	}
}

int	get_dr_end(float bottom)
{
	int	draw_end;

	if (bottom > WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT;
	else
		draw_end = bottom;
	return (draw_end);
}

uint32_t	apply_shading(uint32_t color, char shade)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	float	factor;

	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	if (shade == 'n')
		factor = 0.8;
	else if (shade == 'w' || shade == 'e')
		factor = 0.9;
	else
		factor = 1.0;
	r = (uint8_t)(r * factor);
	g = (uint8_t)(g * factor);
	b = (uint8_t)(b * factor);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	is_door_open(t_game *game, int x, int y)
{
	t_door	*door;

	door = get_door(game->map, x, y);
	return (door && door->open);
}

int	check_open_door(t_game *g, t_ray ray)
{
	int	door_x;
	int	door_y;

	if (ray.hit_door)
	{
		door_x = (int)(ray.wall_hit_x / CELL);
		door_y = (int)(ray.wall_hit_y / CELL);
		if (is_door_open(g, door_x, door_y))
			return (1);
	}
	return (0);
}
