/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:13:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/25 13:53:44 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_collision(t_game *game, float *new_x, float *new_y)
{
	int		radius;
	int		collision;
	float	old_x;
	float	old_y;

	radius = (PLAYER_SIZE / 2) + 1;
	collision = 0;
	old_x = game->player->x;
	old_y = game->player->y;
	if (get_cellchar(game, *new_x - radius, old_y - radius) == '1'
		|| get_cellchar(game, *new_x + radius, old_y - radius) == '1'
		|| get_cellchar(game, *new_x - radius, old_y + radius) == '1'
		|| get_cellchar(game, *new_x + radius, old_y + radius) == '1')
	{
		*new_x = old_x;
		collision = 1;
	}
	if (get_cellchar(game, old_x - radius, *new_y - radius) == '1'
		|| get_cellchar(game, old_x + radius, *new_y - radius) == '1'
		|| get_cellchar(game, old_x - radius, *new_y + radius) == '1'
		|| get_cellchar(game, old_x + radius, *new_y + radius) == '1')
	{
		*new_y = old_y;
		collision = 1;
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
