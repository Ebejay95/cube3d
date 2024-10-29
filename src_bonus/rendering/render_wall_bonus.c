/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:59:37 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 12:29:12 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

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
		|| (ray.verlen > ray.horlen && is_looking_south(ray.current_angle)))
	{
		tex_x = tex->width - tex_x - 1;
	}
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
