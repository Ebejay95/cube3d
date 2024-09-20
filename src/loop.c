/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:21:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/20 11:57:21 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	draw_line(int length, int color,t_game* game )
{
	double  x;
	double  y;
	mlx_image_t* image;

	x = game->minimap->image->instances[0].x + (PIXEL_MINI / 4);
	y = game->minimap->image->instances[0].y + (PIXEL_MINI / 4);
	image = game->minimap->overlay;
	for (int i = 0; i < length; i++)
	{
		if(x > 1 && x < image->width - 1 && y > 1 && y < image->height - 1)
			mlx_put_pixel(image, x, y, color);
		x += game->minimap->delta_x;
		y += game->minimap->delta_y;
	}
}

int	draw_direction(t_game* game)
{
	int pos_x;
	int pos_y;


	if(ft_overlay(game))
		return(1);
	draw_line(5, 0xFFFFFF, game);
	return(0);

}

void	calc_delta(t_game* game, char operator)
{
	if(operator == '+')
	{
		game->minimap->angle += 0.1;
		if(game->minimap->angle >  2 * PI)
			game->minimap->angle -= 2 * PI;
	}
	if(operator == '-')
	{
		game->minimap->angle -= 0.1;
		if(game->minimap->angle < 0)
			game->minimap->angle += 2 * PI;
	}
	game->minimap->delta_x = cos(game->minimap->angle) * 5;
	game->minimap->delta_y = sin(game->minimap->angle) * 5;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		check_move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		check_move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		check_move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		check_move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		calc_delta(game, '+');
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		calc_delta(game, '-');
	if(draw_direction(game))
		return;//return value_!_!_!__!_!
	// printf("X:%i	Y:%i	DX:%f	DY:%f	A:%f\n",game->minimap->image->instances[0].x,game->minimap->image->instances[0].y, game->minimap->delta_x, game->minimap->delta_y, game->minimap->angle);
	// printf("X:%i	Y:%i	POSX:%i	POSY:%i	\n",game->minimap->image->instances[0].x,game->minimap->image->instances[0].y, game->minimap->pos_x, game->minimap->pos_y);

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
