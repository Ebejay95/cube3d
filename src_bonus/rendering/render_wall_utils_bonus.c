/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:00:44 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 10:51:25 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

mlx_texture_t	*get_texture(t_game *game, t_ray ray)
{
	if (ray.hit_door)
		return (game->map->tex_door);
	if (ray.verlen <= ray.horlen)
	{
		if (is_looking_west(ray.current_angle))
			return (game->map->tex_west);
		else
			return (game->map->tex_east);
	}
	else
	{
		if (is_looking_south(ray.current_angle))
			return (game->map->tex_south);
		else
			return (game->map->tex_north);
	}
}

double	get_step_size(t_game *game, mlx_texture_t *texture, int height)
{
	if (texture == game->map->tex_north)
		return ((double)game->map->tex_north->height / height);
	else if (texture == game->map->tex_east)
		return ((double)game->map->tex_east->height / height);
	else if (texture == game->map->tex_south)
		return ((double)game->map->tex_south->height / height);
	else
		return ((double)game->map->tex_west->height / height);
}

int	get_pxl_clr(mlx_texture_t *texture, int x, int y)
{
	unsigned int	i;

	i = (y * texture->width + x) * 4;
	return (get_rgba_colors_hex(texture->pixels[i], texture->pixels[i + 1],
			texture->pixels[i + 2], texture->pixels[i + 3]));
}
