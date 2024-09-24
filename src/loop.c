/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:21:52 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 16:30:25 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dda_raycast(t_game *game, int *hitx, int *hity)
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		hit;

	posx = game->player->x;
	posy = game->player->y;
	dirx = game->minimap->deltax;
	diry = game->minimap->deltay;
	deltadistx = fabs(1 / dirx);
	deltadisty = fabs(1 / diry);
	mapx = (int)posx;
	mapy = (int)posy;
	hit = 0;
	if (dirx < 0)
	{
		stepx = -1;
		sidedistx = (posx - mapx) * deltadistx;
	}
	else
	{
		stepx = 1;
		sidedistx = (mapx + 1.0 - posx) * deltadistx;
	}
	if (diry < 0)
	{
		stepy = -1;
		sidedisty = (posy - mapy) * deltadisty;
	}
	else
	{
		stepy = 1;
		sidedisty = (mapy + 1.0 - posy) * deltadisty;
	}
	while (hit == 0)
	{
		if (sidedistx < sidedisty)
		{
			sidedistx += deltadistx;
			mapx += stepx;
		}
		else
		{
			sidedisty += deltadisty;
			mapy += stepy;
		}
		if (get_cellchar(game, mapx, mapy) == '1')
			hit = 1;
	}
	*hitx = mapx;
	*hity = mapy;
}

void	draw_minimapline(int length, int color, t_game *game)
{
	double			x;
	double			y;
	mlx_image_t		*image;
	int				i;

	x = (game->player->x * (MCELL / (float)CELL));
	y = (game->player->y * (MCELL / (float)CELL));
	image = game->minimap->overlay;
	i = 0;
	while (i < length)
	{
		if (x > 1 && x < image->width - 1 && y > 1 && y < image->height - 1)
			mlx_put_pixel(image, x, y, color);
		x += game->minimap->deltax;
		y += game->minimap->deltay;
		i++;
	}
}

int	draw_direction(t_game *game)
{
	int				hitx;
	int				hity;
	double			start_x;
	double			start_y;
	double			end_x;
	double			end_y;
	mlx_image_t		*image;
	int				dx;
	int				dy;
	int				steps;
	float			x_inc;
	float			y_inc;
	float			x;
	float			y;
	int				i;

	if (ft_overlay(game))
		return (1);
	dda_raycast(game, &hitx, &hity);
	start_x = game->player->x * (MCELL / (float)CELL);
	start_y = game->player->y * (MCELL / (float)CELL);
	end_x = hitx * (MCELL / (float)CELL);
	end_y = hity * (MCELL / (float)CELL);
	image = game->minimap->overlay;
	dx = fabs(end_x - start_x);
	dy = fabs(end_y - start_y);
	if (dx > dy)
		steps = dx;
	else
		steps = dy;
	x_inc = (end_x - start_x) / (float)steps;
	y_inc = (end_y - start_y) / (float)steps;
	x = start_x;
	y = start_y;
	i = 0;
	while (i <= steps)
	{
		if (x > 1 && x < image->width - 1 && y > 1 && y < image->height - 1)
			mlx_put_pixel(image, x, y, 0xFFFFFF);
		x += x_inc;
		y += y_inc;
		i++;
	}
	return (0);
}

void	calc_delta(t_game *game, char operator)
{
	float	angle_increment;

	angle_increment = 0.1;
	if (operator == '+')
	{
		game->player->angle += angle_increment;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
	}
	else if (operator == '-')
	{
		game->player->angle -= angle_increment;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
	}
	game->minimap->deltax = cos(game->player->angle);
	game->minimap->deltay = sin(game->player->angle);
	game->minimap->angle = game->player->angle;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	bool	is_pressed;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	is_pressed = (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT);
	if (keydata.key == MLX_KEY_W)
		game->key_states.w_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_S)
		game->key_states.s_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_A)
		game->key_states.a_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_D)
		game->key_states.d_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_LEFT)
		game->key_states.left_pressed = is_pressed;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->key_states.right_pressed = is_pressed;
}

void	update_game_state(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->key_states.w_pressed)
		check_move_up(game);
	if (game->key_states.s_pressed)
		check_move_down(game);
	if (game->key_states.a_pressed)
		check_move_left(game);
	if (game->key_states.d_pressed)
		check_move_right(game);
	if (game->key_states.left_pressed)
		calc_delta(game, '-');
	if (game->key_states.right_pressed)
		calc_delta(game, '+');
	draw_direction(game);
}

void	start_game(t_game *game)
{
	if (game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->mlx, &key_hook, game);
		mlx_loop_hook(game->mlx, &update_game_state, game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
}
