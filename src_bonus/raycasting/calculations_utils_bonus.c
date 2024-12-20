/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:02:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/11 15:19:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

int	is_position_in_map(t_game *game, int pos_y, int pos_x)
{
	if (game->map->content[pos_y]
		&& (pos_x <= (int)ft_strlen(game->map->content[pos_y])))
		return (1);
	return (0);
}

int	is_wall(t_game *game, float xv, float yv)
{
	int	y;
	int	x;

	y = floor(yv / CELL);
	x = floor(xv / CELL);
	if (y >= game->map->height || y < 0)
		return (1);
	if (x >= game->map->width || x < 0)
		return (1);
	if (is_position_in_map(game, y, x))
		if (game->map->content[y][x] == '1')
			return (1);
	return (0);
}

int	get_h_drctn(float current_angle, float *y,
		float *len_y)
{
	if (is_looking_right(current_angle) || is_looking_down(current_angle))
	{
		*y = *y + CELL;
		return (-1);
	}
	*len_y = *len_y * (-1);
	return (1);
}

int	get_v_drctn(float current_angle, float *x,
		float *len_x)
{
	if (is_looking_right(current_angle) || is_looking_up(current_angle))
	{
		*x = *x + CELL;
		return (-1);
	}
	*len_x = *len_x * (-1);
	return (1);
}

float	calculate_len(t_game *game, float x, float y)
{
	float	len_x;
	float	len_y;

	len_x = x - game->player->x;
	len_y = y - game->player->y;
	return (sqrt(pow(len_x, 2) + pow(len_y, 2)));
}
