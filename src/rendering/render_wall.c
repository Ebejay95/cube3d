/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/08 16:54:18 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_game *game, t_ray ray, int top, int bottom)
{
	double			step;
	int				tex_pos_y;
	uint32_t		color;
	mlx_texture_t	*tex;
	double			tex_index;

	tex = get_texture(game, ray);
	step = get_step_size(game, tex, abs(bottom) - abs(top));
	tex_index = 0;
	while (abs(top) < abs(bottom) && abs(top) < WINDOW_HEIGHT)
	{
		tex_pos_y = (int)tex_index % tex->height;
		tex_index += step;
		color = get_pixel_color(tex, get_x_pos(game, ray, tex), tex_pos_y);
		mlx_put_pixel(game->surface, ray.index, abs(top), color);
		top++;
	}
}
