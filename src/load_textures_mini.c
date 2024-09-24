/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 16:32:24 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	ft_load_map(t_game *game, char c, int color)
{
	int				x;
	int				y;
	mlx_image_t		*image;

	x = 0;
	y = 0;
	image = mlx_new_image(game->mlx, MCELL - 1, MCELL - 1);
	if (!image)
		return (1);
	(void) c;
	ft_set_color_minimap_char(image, color);
	while (x < game->minimap->map_width)
	{
		y = 0;
		while (y < game->minimap->map_height)
		{
			if (game->map->content[y] && game->map->content[y][x] == c)
			{
				if (mlx_image_to_window(game->mlx, image, x * MCELL, y * MCELL) == -1)
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_load_minimap(t_game *game)
{
	int	i;

	i = 0;
	i += ft_load_map(game, '0', 0x100000FF);
	i += ft_load_map(game, 'N', 0x100000FF);
	i += ft_load_map(game, 'E', 0x100000FF);
	i += ft_load_map(game, 'W', 0x100000FF);
	i += ft_load_map(game, 'S', 0x100000FF);
	i += ft_load_map(game, '1', 0x1FF000FF);
	return (i);
}

int	ft_load_minimap_entities(t_game *game)
{
	float	pos_x;
	float	pos_y;

	pos_x = game->player->x * (MCELL / (float)CELL);
	pos_y = game->player->y * (MCELL / (float)CELL);
	game->minimap->player = mlx_new_image(game->mlx, PLAYER_SIZE, PLAYER_SIZE);
	if (!game->minimap->player)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap->player, pos_x - PLAYER_SIZE / 2, pos_y - PLAYER_SIZE / 2) == -1)
		return (1);
	ft_set_color_minimap_char(game->minimap->player, 0xFF00FFFF);
	if (game->minimap->player->instances)
	{
		game->minimap->player->instances[0].x = pos_x - PLAYER_SIZE / 2;
		game->minimap->player->instances[0].y = pos_y - PLAYER_SIZE / 2;
	}
	return (0);
}

int	ft_overlay(t_game *game)
{
	if (game->minimap->overlay)
		mlx_delete_image(game->mlx, game->minimap->overlay);
	game->minimap->overlay = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (!game->minimap->overlay)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap->overlay, 0, 0) == -1)
		return (1);
	ft_set_color_minimap_char(game->minimap->overlay, 0x00000001);
	return (0);
}

int	ft_load_textures_minimap(t_game *game)
{
	int	i;

	i = 0;
	i += ft_load_minimap(game);
	i += ft_load_minimap_entities(game);
	return (i);
}
