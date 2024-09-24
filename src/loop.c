/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:21:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 14:42:11 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void draw_minimapline(int length, int color, t_game* game)
{
    double  x;
    double  y;
    mlx_image_t* image;

    // Calculate the center point of the player on the minimap
    x = (game->player->x * (MCELL / (float)CELL));
    y = (game->player->y * (MCELL / (float)CELL));

    image = game->minimap->overlay;
    for (int i = 0; i < length; i++)
    {
        if(x > 1 && x < image->width - 1 && y > 1 && y < image->height - 1)
            mlx_put_pixel(image, x, y, color);
        x += game->minimap->delta_x;
        y += game->minimap->delta_y;
    }
}

int	draw_the_ray(t_game* game)
{
	printf("Player at: %i %i, %f\n", game->player->y, game->player->x, game->player->angle);
	return(0);
}

int	draw_direction(t_game* game)
{
	if(ft_overlay(game))
		return(1);
	draw_minimapline(20, 0xFFFFFF, game);
	return(0);
}

void calc_delta(t_game* game, char operator)
{
    float angle_increment = 0.1; // You might want to adjust this value

    if(operator == '+')
    {
        game->player->angle += angle_increment;
        if(game->player->angle > 2 * PI)
            game->player->angle -= 2 * PI;
    }
    else if(operator == '-')
    {
        game->player->angle -= angle_increment;
        if(game->player->angle < 0)
            game->player->angle += 2 * PI;
    }
    ft_printf("calc_delta: %i %i, %f\n", game->player->y, game->player->x, game->player->angle);
    game->minimap->delta_x = cos(game->player->angle);
    game->minimap->delta_y = sin(game->player->angle);
    game->minimap->angle = game->player->angle;
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
		return;
	if(draw_the_ray(game))
		return;//return value_!_!_!__!_!
	// printf("DX:%f DY:%f A:%f\n",game->minimap->delta_x, game->minimap->delta_y, game->minimap->angle);
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
