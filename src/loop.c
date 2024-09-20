/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:21:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/20 10:37:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

// void    draw_line(mlx_image_t *image, int x0, int y0, int length, int color, float rx, float ry)
void    draw_line(mlx_image_t *image, int x0, int y0, double angle, int length, int color, float rx, float ry)
{
	// double  radian = angle * M_PI / 180; // Convert angle to radians
    // double  dx = cos(radian);  // The change in x for each step
    // double  dy = sin(radian);  // The change in y for each step
    double  x = x0;
    double  y = y0;

	printf("x: %f y:%f\n", x, y);

    for (int i = 0; i < length; i++)
    {
		if(x > 1 && x < image->width - 1 && y > 1 && y < image->height - 1)
			mlx_put_pixel(image, x, y, color);
        // x += dx;  // Increment the x coordinate
        // y += dy;  // Increment the y coordinate
        x += rx;  // Increment the x coordinate
        y += ry;  // Increment the y coordinate
    }
}


int	draw_direction(t_game* game)
{
	int pos_x;
	int pos_y;

	pos_x = (game->minimap->image->instances[0].x / PIXEL_MINI);
	pos_y = (game->minimap->image->instances[0].y / PIXEL_MINI);
	if(ft_overlay(game))
		return(1);
	draw_line(game->minimap->overlay, pos_x, pos_y, game->minimap->angle, 20, 0xFFFFFF, game->minimap->delta_x, game->minimap->delta_y);
	return(0);

}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		check_move_up(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		check_move_down(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		check_move_left(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		check_move_right(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->minimap->angle += 0.1;
		if(game->minimap->angle >  2 * PI)
			game->minimap->angle -= 2 * PI;
		game->minimap->delta_x = cos(game->minimap->angle) * 5;
		game->minimap->delta_y = sin(game->minimap->angle) * 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->minimap->angle -= 0.1;
		if(game->minimap->angle < 0)
			game->minimap->angle += 2 * PI;
		game->minimap->delta_x = cos(game->minimap->angle) * 5;
		game->minimap->delta_y = sin(game->minimap->angle) * 5;
	}
	if(draw_direction(game))
		return;//return value_!_!_!__!_!
	printf("X:%i	Y:%i	DX:%f	DY:%f	A:%f\n",game->minimap->image->instances[0].x,game->minimap->image->instances[0].y, game->minimap->delta_x, game->minimap->delta_y, game->minimap->angle);
	printf("TEST:X:%i	Y:%i	\n", game->minimap->pos_x, game->minimap->pos_y);

	return ;
}


void	start_game(t_game *game)
{
	if (game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->mlx, &my_keyhook, game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
}
