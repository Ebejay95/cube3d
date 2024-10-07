/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 09:19:48 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(mlx_image_t *surface,int index_of_ray ,int top)
{
	while (top)
	{
		draw_pixel(surface, index_of_ray, top, WALL_COLOR3);
		top--;
	}
}

void	draw_floor(mlx_image_t *surface,int index_of_ray ,int bottom)
{
	while (bottom < WINDOW_HEIGHT)
	{
		draw_pixel(surface, index_of_ray, bottom, WALL_COLOR2);
		bottom++;
	}
}

// Function to retrieve the pixel color from the texture at given coordinates
int	get_pixel_color(mlx_texture_t *texture, int i)
{
	return get_rgba_colors_hex(
		texture->pixels[i],
		texture->pixels[i + 1],
		texture->pixels[i + 2],
		texture->pixels[i + 3]
	);
}

// Function to determine which texture to load based on the view/ray angle
mlx_image_t* get_image(t_game* game, float current_angle)
{
	float angle;

	angle = angle_check(current_angle);
	if (is_looking_left(angle))
		return game->map->img_west;
	else if (is_looking_down(angle))
		return game->map->img_south;
	else if (is_looking_up(angle))
		return game->map->img_north;
	// else if (is_looking_right(angle))
	else
		return game->map->img_east;
}

double	get_step_size(t_game* game, mlx_image_t* image, int height)
{
	if(image == game->map->img_north)
		return((double)game->map->tex_north->height / height);
	else if(image == game->map->img_east)
		return((double)game->map->tex_east->height / height);
	else if(image == game->map->img_south)
		return((double)game->map->tex_south->height / height);
	else
		return((double)game->map->tex_west->height / height);
}

// Calculate the texture x-coordinate based on the wall hit position
int	get_x_pos(t_ray ray, int texture_width)
{
	double	relative_pos;
	int		texture_x;

	if (is_looking_left(ray.current_angle) || is_looking_right(ray.current_angle))
		relative_pos = fmod(ray.horizontal_len, CELL); // For West/East
	else
		relative_pos = fmod(ray.vertical_len, CELL); // For North/South
	texture_x = (int)(relative_pos / CELL * texture_width);
	if (is_looking_left(ray.current_angle) || is_looking_down(ray.current_angle))
		texture_x = texture_width - texture_x - 1;
	return texture_x;
}

int get_y_pos(float top,float bottom,double step)
{
	if ((bottom - top) > WINDOW_HEIGHT)
		return((top - WINDOW_HEIGHT / 2) + ((bottom - top) / 2) * step);
	else
		return(WINDOW_HEIGHT);
}

// mlx_image_t *surface
void	draw_wall(t_game* game, t_ray ray ,int top, int bottom)
{
	// double	step;
	// int		tex_pos_x;
	// int		tex_pos_y;
	// uint32_t color;
	// int	pos;

	// mlx_image_t* image;

	// image = get_image(game, ray.current_angle);
	// // image = game->map->img_north;
	// step = get_step_size(game, image, bottom - top);
	// tex_pos_x = get_x_pos(ray, game->map->tex_north->width);
	// tex_pos_y = get_y_pos(top, bottom, step);
	// pos = 0;
	// top=0;
	// printf("%i %i\n", tex_pos_x, tex_pos_y);
	// while (top < bottom && top < WINDOW_HEIGHT)
	// {

	// 	// color = get_pixel_color(image, tex_pos_x, tex_pos_y);
	// 	color = get_pixel_color(game->map->img_east, top, 0);
	// 	mlx_put_pixel(game->surface, tex_pos_x, top, color);
	// 	top++;
	// }
		unsigned int	i;
	uint32_t color;

	i = 0;
	if(ray.index % 4 == 0)
		i = 0;
	else if(ray.index % 4 == 1)
		i = game->map->tex_north->height + 1;
	else if(ray.index % 4 == 2)
		i = game->map->tex_north->height * 2 + 1;
	else if(ray.index % 4 == 3)
		i = game->map->tex_north->height * 3 + 1;

	while (top < bottom)
	{
		color = get_pixel_color(game->map->tex_north, i);
		// color = get_rgba_colors_hex(game->map->tex_north->pixels[i],game->map->tex_north->pixels[i + 1],game->map->tex_north->pixels[i + 2],game->map->tex_north->pixels[i+3]);
		draw_pixel(game->surface, ray.index, top, color);
		top++;
		i += 4;
		if(i > (game->map->tex_north->height * game->map->tex_north->bytes_per_pixel)) // >= ?
			i = 0;
	}
}


void	rendering_wall(t_game* game, t_ray ray)
{
	float bottom;
	float top;
	float wall_height;

	ray.len = fish_eye_correction(game, ray.len, ray.current_angle);
	wall_height = (CELL / ray.len) * ((WINDOW_HEIGHT/2) / tan(FOV / 2));
	calculate_wall_slice_height(wall_height, &top, &bottom);
	draw_ceiling(game->surface, ray.index, top);
	draw_floor(game->surface, ray.index, bottom);
	draw_wall(game, ray, top, bottom);
}
