/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 10:08:57 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// mlx_image_t *surface
void	draw_wall(t_game* game, t_ray ray ,int top, int bottom)
{
	double	step;
	int		tex_pos_x;
	int		tex_pos_y;
	// int		pos;
	uint32_t color;
	mlx_texture_t* texture;

	texture = get_texture(game, ray.current_angle);
	step = get_step_size(game, texture, bottom - top);
	tex_pos_x = get_x_pos(ray, texture->width);
	tex_pos_y = get_y_pos(top, bottom, step);
	printf("%i %i\n", tex_pos_x, tex_pos_y);
	while (top < bottom && top < WINDOW_HEIGHT)
	{
		color = get_pixel_color(texture, top);
		mlx_put_pixel(game->surface, ray.index, top, color);
		top++;
	}
}
