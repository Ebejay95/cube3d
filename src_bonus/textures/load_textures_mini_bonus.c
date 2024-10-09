/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_mini_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:58:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/09 23:59:03 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	ft_set_color_minimap_char(mlx_image_t *image, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	while (x < image->width)
	{
		while (y < image->height)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

int	ft_load_textures_minimap(t_game *game)
{
	int	i;

	i = 0;
	game->mouse_locked = true;
	return (i);
}
