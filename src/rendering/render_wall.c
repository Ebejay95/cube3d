/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 13:13:06 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
static int	c_tex_x(t_ray ray, int texture_width)
{
	double	relative_pos;
	int		texture_x;

	// if (data->ray.flag == 0)
	if (is_looking_left(ray.current_angle) || is_looking_right(ray.current_angle))
		relative_pos = fmod(ray.vertical_len, CELL);
	else
		relative_pos = fmod(ray.vertical_len, CELL);
	texture_x = (int)(relative_pos / CELL * texture_width);
	// if (data->f_tex == WEST || data->f_tex == SOUTH)
	// 	texture_x = texture_width - texture_x - 1;
	if (is_looking_left(ray.current_angle) || is_looking_down(ray.current_angle))
		texture_x = texture_width - texture_x - 1;
	return (texture_x);
}

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	get_pixel_color2(mlx_texture_t *texture, int x, int y)
{
	unsigned int	i;

	i = (y * texture->width + x) * 4;
	return (get_rgba(texture->pixels[i], texture->pixels[i + 1],
			texture->pixels[i + 2], texture->pixels[i + 3]));
}

// mlx_image_t *surface
void	draw_wall(t_game* game, t_ray ray ,int top, int bottom)
{
	double	step;
	int		tex_pos_x;
	int		tex_pos_y = 0.0;
	int		index;
	int		pos_pixel;
	uint32_t color;
	mlx_texture_t* texture;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	texture = get_texture(game, ray);
	step = (double)texture->height / (bottom - top);
	tex_x = c_tex_x(ray, texture->width);
	tex_pos = 0;
	while (top < bottom && top < WINDOW_HEIGHT)
	{
		tex_y = (int)tex_pos % texture->height;
		tex_pos += step;
		if (top < 0)
		{
			top++;
			continue ;
		}
		mlx_put_pixel(game->surface, ray.index, top++,
		get_pixel_color2(texture, tex_x, tex_y));
	}


	// texture = get_texture(game, ray.current_angle);
	// step = get_step_size(game, texture, bottom - top);
	// tex_pos_x = get_x_pos(ray, texture->width);
	// tex_pos_y = get_y_pos(top, bottom, step);
	// index = 0;
	// printf("%i %.2f\n", tex_pos_x, step);
	// while (top < bottom && top < WINDOW_HEIGHT)
	// {
	// 	// tex_pos_y = (int)index % (texture->height);
	// 	// index += step;
	// 	// printf("%i %i\n", tex_pos_x, tex_pos_y);
	// 	// printf("%i \n", texture->width);

	// 	tex_pos_y = fmod(index, texture->height); // wrap around if tex_pos_y exceeds height
	// 	index += step;

	// 	pos_pixel = (int)(tex_pos_y * texture->width + tex_pos_x) * texture->bytes_per_pixel;
	// 	color = get_pixel_color(texture, pos_pixel);
	// 	mlx_put_pixel(game->surface, ray.index, top, color);
	// 	top++;
	// }
}
