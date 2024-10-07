/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:34:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 15:31:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	fish_eye_correction(t_game *game, float ray_len, float current_angle)
{
	return (ray_len * cos((current_angle - game->player->angle)));
}

void	calculate_wall_slice_height(float height, float *top, float *bottom)
{
	*top = (WINDOW_HEIGHT / 2) - (height / 2);
	*bottom = (WINDOW_HEIGHT / 2) + (height / 2);
	if (*bottom > WINDOW_HEIGHT)
		*bottom = WINDOW_HEIGHT;
	if (*top < 0)
		*top = 0;
}

void	draw_pixel(mlx_image_t *image, float x, float y, uint32_t color)
{
	if (x >= 0 && x < image->width && y >= 0 && y < image->height)
	{
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, color);
	}
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
	return (0);
}

int	get_rgba_colors_hex(int red, int green, int blue, int alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}
