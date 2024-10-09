/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:55:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/09 23:56:22 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	check_collision(t_game *game, float *new_x, float *new_y)
{
	int		radius;
	float	old_x;
	float	old_y;

	radius = (PLAYER_SIZE / 2) + 1;
	old_x = game->player->x;
	old_y = game->player->y;
	if (get_cellchar(game, *new_x - radius, old_y - radius) == '1'
		|| get_cellchar(game, *new_x + radius, old_y - radius) == '1'
		|| get_cellchar(game, *new_x - radius, old_y + radius) == '1'
		|| get_cellchar(game, *new_x + radius, old_y + radius) == '1')
	{
		*new_x = old_x;
	}
	if (get_cellchar(game, old_x - radius, *new_y - radius) == '1'
		|| get_cellchar(game, old_x + radius, *new_y - radius) == '1'
		|| get_cellchar(game, old_x - radius, *new_y + radius) == '1'
		|| get_cellchar(game, old_x + radius, *new_y + radius) == '1')
	{
		*new_y = old_y;
	}
}

char	get_cellchar(t_game *game, int x, int y)
{
	int	cell_x;
	int	cell_y;

	cell_x = x / CELL;
	cell_y = y / CELL;
	return (game->map->content[cell_y][cell_x]);
}
