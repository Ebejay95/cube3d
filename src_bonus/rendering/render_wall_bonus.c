/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:59:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 22:23:39 by jeberle          ###   ########.fr       */
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

int	get_draw_start(int top)
{
	if (top < 0)
		return (0);
	return (top);
}

float	calculate_wall_x(t_ray ray)
{
	if (ray.verlen <= ray.horlen)
		return (ray.wall_hit_y);
	return (ray.wall_hit_x);
}

int	calculate_tex_x(float wall_x, mlx_texture_t *tex, t_ray ray)
{
	int	tex_x;

	wall_x = fmodf(wall_x, CELL);
	tex_x = (int)(wall_x * tex->width / CELL);
	if ((ray.verlen <= ray.horlen && is_looking_west(ray.current_angle))
		|| (ray.verlen > ray.horlen && is_looking_north(ray.current_angle)))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	wallpxls(t_wall_data *d)
{
	double		t;
	int			y;
	uint32_t	clr;
	int			s;

	s = get_draw_start(d->top);
	t = (s - d->top) * get_step_size(d->game, d->texture, d->bottom - d->top);
	y = s;
	while (y < get_dr_end(d->bottom))
	{
		t += get_step_size(d->game, d->texture, d->bottom - d->top);
		clr = get_pxl_clr(d->texture, d->tex_x, (int)t % d->texture->height);
		clr = apply_shading(clr, get_shade(d->ray));
		mlx_put_pixel(d->game->surface, d->ray.index, y, clr);
		y++;
	}
}

void	draw_wall(t_game *g, t_ray ray, int top, int bottom)
{
	t_wall_data		wall_data;
	mlx_texture_t	*tex;
	float			wall_x;

	if (check_open_door(g, ray))
		return ;
	tex = get_texture(g, ray);
	wall_x = calculate_wall_x(ray);
	wall_data.game = g;
	wall_data.ray = ray;
	wall_data.top = top;
	wall_data.bottom = bottom;
	wall_data.texture = tex;
	wall_data.tex_x = calculate_tex_x(wall_x, tex, ray);
	wallpxls(&wall_data);
}
