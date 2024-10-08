/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/08 12:39:52 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_game *game, t_ray ray, int top, int bottom)
{
	double			step;
	int				tex_pos_x;
	int				tex_pos_y;
	uint32_t		color;
	mlx_texture_t	*texture;
	double			tex_index;

	texture = get_texture(game, ray);
	step = get_step_size(game, texture, abs(bottom) - abs(top));
	tex_pos_x = get_x_pos(game, ray, texture);
	tex_index = 0;
	while (abs(top) < abs(bottom) && abs(top) < WINDOW_HEIGHT)
	{
		tex_pos_y = (int)tex_index % texture->height;
		tex_index += step;
		// if(top < 0)
		// {
		// 	top++;
		// 	continue;
		// }
		color = get_pixel_color(texture, tex_pos_x, tex_pos_y);
		mlx_put_pixel(game->surface, ray.index, abs(top), color);
		top++;
	}
}
