/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:59:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 15:14:28 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

char	get_shade(t_ray ray)
{
	if (ray.vertical_len <= ray.horizontal_len)
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

void	draw_wall(t_game *g, t_ray ray, int top, int bottom)
{
	uint32_t		clr;
	mlx_texture_t	*tex;
	double			t_idx;
	int				draw_start;
	int				y;
	float			wall_x;
	int				tex_x;

	tex = get_texture(g, ray);
	if (top < 0)
		draw_start = 0;
	else
		draw_start = top;
	t_idx = (draw_start - top) * get_step_size(g, tex, bottom - top);
	y = draw_start;
	if (ray.vertical_len <= ray.horizontal_len)
		wall_x = ray.wall_hit_y;
	else
		wall_x = ray.wall_hit_x;
	wall_x = fmodf(wall_x, CELL);
	tex_x = (int)(wall_x * tex->width / CELL);
	if ((ray.vertical_len <= ray.horizontal_len && is_looking_west(ray.current_angle))
		|| (ray.vertical_len > ray.horizontal_len && is_looking_north(ray.current_angle)))
		tex_x = tex->width - tex_x - 1;
	while (y < get_dr_end(bottom))
	{
		t_idx += get_step_size(g, tex, bottom - top);
		clr = get_pxl_clr(tex, tex_x, (int)t_idx % tex->height);
		clr = apply_shading(clr, get_shade(ray));
		mlx_put_pixel(g->surface, ray.index, y, clr);
		y++;
	}
}
