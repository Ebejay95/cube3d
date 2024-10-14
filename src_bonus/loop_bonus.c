/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:57:14 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 22:05:33 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	calc_delta(t_game *game, char operator)
{
	float	angle_incr;

	angle_incr = 0.06;
	if (operator == '+')
		game->player->angle = angle_check(game->player->angle + angle_incr);
	else if (operator == '-')
		game->player->angle = angle_check(game->player->angle - angle_incr);
	game->deltax = cos(game->player->angle);
	game->deltay = sin(game->player->angle);
	game->angle = game->player->angle;
}

void	key_listener(t_game *game, mlx_key_data_t kd, float distance)
{
	float	door_x;
	float	door_y;

	if (kd.key == MLX_KEY_W)
		game->key_states.w_pressed = game->is_pressed;
	else if (kd.key == MLX_KEY_S)
		game->key_states.s_pressed = game->is_pressed;
	else if (kd.key == MLX_KEY_A)
		game->key_states.a_pressed = game->is_pressed;
	else if (kd.key == MLX_KEY_D)
		game->key_states.d_pressed = game->is_pressed;
	else if (kd.key == MLX_KEY_LEFT)
		game->key_states.left_pressed = game->is_pressed;
	else if (kd.key == MLX_KEY_RIGHT)
		game->key_states.right_pressed = game->is_pressed;
	else if (kd.key == MLX_KEY_SPACE && kd.action == MLX_PRESS)
	{
		distance = find_nearest_door(game, &door_x, &door_y);
		if (distance >= 0 && distance <= MAX_DOOR_DISTANCE)
		{
			toggle_door(game, (int)(door_x / CELL), (int)(door_y / CELL));
		}
	}
}

void	key_hook(mlx_key_data_t kd, void *param)
{
	t_game	*game;
	float	distance;

	distance = 0;
	game = (t_game *)param;
	if (kd.key == MLX_KEY_ESCAPE && kd.action == MLX_PRESS)
	{
		game->run_music = false;
		mlx_close_window(game->mlx);
		return ;
	}
	game->is_pressed = (kd.action == MLX_PRESS || kd.action == MLX_REPEAT);
	key_listener(game, kd, distance);
	if (kd.key == MLX_KEY_ENTER && kd.action == MLX_PRESS)
	{
		game->animating_hand = true;
		ft_printf("MLX_KEY_ENTER\n");
	}
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
	ft_surface(game);
	ray_calculation(game);
	render_minimap(game);
	//render_hand(game);
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
