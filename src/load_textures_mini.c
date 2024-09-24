/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 06:58:33 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_set_color_minimap_char(mlx_image_t *image, uint32_t color)
{
	uint32_t x;
	uint32_t y;

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
    mlx_image_t* image = mlx_new_image(game->mlx, PIXEL_MINI - 1, PIXEL_MINI - 1);
    if (!image) {
        return (1);
    }
    (void) c;
    ft_set_color_minimap_char(image, color);
    printf("height %i, width %i\n", game->minimap->map_height, game->minimap->map_width);
    while (x < game->minimap->map_width)
    {
        y = 0;
        while (y < game->minimap->map_height)
        {
			printf("x %i, y %i\n",x , y);
            if (game->map->content[y] && game->map->content[y][x] == c)
            {
                if (mlx_image_to_window(game->mlx, image, x * PIXEL_MINI, y * PIXEL_MINI) == -1)
                    return (1);
            }
            y++;
        }
        x++;
    }
    return (0);
}

int ft_load_minimap(t_game *game)
{
	int	i;

	i = 0;
	i += ft_load_map(game, '0', 0x100000FF);
	i += ft_load_map(game, 'P', 0x100000FF);
	i += ft_load_map(game, '1', 0x1FF000FF);
	return(i);
}

int	ft_load_mini_char(t_game *game)
{
	int pos_x;
	int pos_y;

	pos_x = (game->minimap->pos_x * PIXEL_MINI) + (PIXEL_MINI / OFFSET);
	pos_y = (game->minimap->pos_y * PIXEL_MINI) + (PIXEL_MINI / OFFSET);
	game->minimap->image = mlx_new_image(game->mlx, PIXEL_MINI_CHAR, PIXEL_MINI_CHAR);
	if (!game->minimap->image)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap->image, pos_x, pos_y) == -1)
		return (1);
	ft_set_color_minimap_char(game->minimap->image, 0xFF00FFFF);
	return (0);
}

int ft_overlay(t_game* game)
{
	if(game->minimap->overlay)
		mlx_delete_image(game->mlx,game->minimap->overlay);
	game->minimap->overlay = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);//width and height musst only be as big as minimap? but can be left for the whole to show some other things
	if (!game->minimap->overlay)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap->overlay, 0, 0) == -1)
		return (1);
	ft_set_color_minimap_char(game->minimap->overlay, 0x00000001);
	return(0);
}

int	ft_load_textures_minimap(t_game *game)
{
	int	i;

	i = 0;
	i += ft_load_minimap(game);
	i += ft_load_mini_char(game);
	i += ft_overlay(game);
	return (i);
}
