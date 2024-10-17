/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:39:12 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/17 17:14:30 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	calc_delta(t_game *game, char operator, int factor)
{
	float	angle_incr;

	angle_incr = 0.06;
	if (operator == '+')
		game->player->angle = angle_check(game->player->angle + angle_incr);
	else if (operator == '-')
		game->player->angle = angle_check(game->player->angle - angle_incr);
	game->deltax = factor * cos(game->player->angle);
	game->deltay = factor * sin(game->player->angle);
	game->angle = game->player->angle;
}

void	render_hand(t_game *game)
{
	int	x;
	int	y;

	x = 345;
	y = 345;
	if (mlx_image_to_window(game->mlx, game->hand_images[0], x, y) < 0)
	{
		printf("Error: Failed to add hand image to window\n");
		return ;
	}
}
