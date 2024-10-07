/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:52:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 09:59:32 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Function to determine which texture to load based on the view/ray angle
mlx_texture_t* get_texture(t_game* game, float current_angle)
{
	float angle;

	angle = angle_check(current_angle);
	if (is_looking_left(angle))
		return game->map->tex_west;
	else if (is_looking_down(angle))
		return game->map->tex_south;
	else if (is_looking_up(angle))
		return game->map->tex_north;
	else
		return game->map->tex_east;
}

double	get_step_size(t_game* game, mlx_texture_t* texture, int height)
{
	if(texture == game->map->tex_north)
		return((double)game->map->tex_north->height / height);
	else if(texture == game->map->tex_east)
		return((double)game->map->tex_east->height / height);
	else if(texture == game->map->tex_south)
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
		relative_pos = fmod(ray.horizontal_len, CELL);
	else
		relative_pos = fmod(ray.vertical_len, CELL);
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
