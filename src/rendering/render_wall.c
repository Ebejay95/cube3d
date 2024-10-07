/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 15:38:39 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_pixel_color2(mlx_texture_t *texture, int x, int y)
{
	unsigned int	i;

	i = (y * texture->width + x) * 4;
	return (get_rgba_colors_hex(texture->pixels[i], texture->pixels[i + 1],
			texture->pixels[i + 2], texture->pixels[i + 3]));
}

void	draw_wall(t_game *game, t_ray ray, int top, int bottom)
{
	double			step;
	int				tex_pos_x;
	int				tex_pos_y;
	uint32_t		color;
	mlx_texture_t	*texture;
	double			tex_index;

	texture = get_texture(game, ray);
	step = get_step_size(game, texture, bottom - top);
	tex_pos_x = get_x_pos(ray, texture->width);
	tex_index = 0;
	while (top < bottom && top < WINDOW_HEIGHT)
	{
		tex_pos_y = (int)tex_index % texture->width;
		tex_index += step;
		color = get_pixel_color2(texture, tex_pos_x, tex_pos_y);
		mlx_put_pixel(game->surface, ray.index, top, color);
		top++;
	}
}
