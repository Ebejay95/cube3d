/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:39:12 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 11:55:29 by ajehle           ###   ########.fr       */
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
