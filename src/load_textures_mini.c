/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 09:27:38 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_set_color_minimap_char(mlx_image_t *image, uint32_t color)
{
	int x;
	int y;

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

int ft_load_map(t_game *game, char c, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_image_t* image = mlx_new_image(game->mlx, PIXEL - 1, PIXEL - 1);

	ft_set_color_minimap_char(image, color);
	// printf("height %i, width %i\n",game->map->height / PIXEL, game->map->width / PIXEL);
	printf("height %i, width %i\n",game->minimap->height , game->minimap->width);
	// while (x < game->map->width / PIXEL)
	while (x < game->minimap->width)
	{
	printf("x %i, y %i\n",x , y);

		// while (y < game->map->height / PIXEL)
		while (y < game->minimap->height)
		{
			// if(game->map->map_as_arr[x][y] == c)
			// {
			// 	// if (mlx_image_to_window(game->mlx, image, x * PIXEL, y * PIXEL) == -1)
				if (mlx_image_to_window(game->mlx, image, x, y ) == -1)
					return (1);
			// }
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int ft_load_minimap(t_game *game)
{
	int	i;

	i = 0;
	i += ft_load_map(game, '0', 0x100000FF);
	i += ft_load_map(game, '1', 0x1FF000FF);
	return(i);
}

int	ft_load_mini_char(t_game *game)
{
	int pos_x;
	int pos_y;

	pos_x = game->minimap->pos_x;
	pos_y = game->minimap->pos_y;
	game->minimap->image = mlx_new_image(game->mlx, PIXEL / 2, PIXEL / 2);
	if (!game->minimap->image)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap->image, (pos_x * PIXEL) + (PIXEL / OFFSET), (pos_y * PIXEL) + (PIXEL / OFFSET)) == -1)
		return (1);
	ft_set_color_minimap_char(game->minimap->image, 0xFF00FFFF);

	return (0);
}

int ft_overlay(t_game* game)
{
	if(game->minimap->overlay)
		mlx_delete_image(game->mlx,game->minimap->overlay);
	game->minimap->overlay = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (!game->minimap->overlay)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap->overlay, 0, 0) == -1)
		return (1);
	ft_set_color_minimap_char(game->minimap->overlay, 0x00000000);
	return(0);
}

int	ft_load_textures_minimap(t_game *game)
{
	int	i;

	i = 0;
	i += ft_overlay(game);
	i += ft_load_minimap(game);
	i += ft_load_mini_char(game);
	return (i);
}
