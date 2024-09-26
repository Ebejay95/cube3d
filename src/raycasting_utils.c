/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:24:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/26 14:48:42 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



float	angle_check(float angle)
{
	if (angle > 2 * PI)
		return(angle - 2 * PI);
	else if (angle < 0)
		return(angle + 2 * PI);
	else
		return (angle);
}


float to_radian(float angle)
{
	return ((angle / 180)  * PI);
}



int	ft_surface(t_game *game)
{
	if (game->surface)
		mlx_delete_image(game->mlx, game->surface);
	game->surface = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->surface)
		return (1);
	if (mlx_image_to_window(game->mlx, game->surface, 0, 0) == -1)
		return (1);
	// ft_set_color_minimap_char(game->surface, 0x000001); //not needed???
	return (0);
}


float	calculate_steps(float dx, float dy)
{
	if (fabsf(dx) > fabsf(dy))
		return (fabsf(dx));
	else
		return (fabsf(dy));
}

void	draw_pixel(mlx_image_t *image, float x, float y, uint32_t color)
{
	if (x >= 0 && x < image->width && y >= 0 && y < image->height)
	{
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, color);
	}
}
