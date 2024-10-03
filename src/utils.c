/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:13:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/29 09:41:19 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
