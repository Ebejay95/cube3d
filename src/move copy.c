/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 17:02:55 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_move_up1(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y + 1;
	x = game->minimap->pos_x;
	c = game->map->content[y][x];
	print_2d_arr(game->map->content);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].y -= PLAYER_STEP;
		game->minimap->pos_y -= PLAYER_STEP;
		return (0);
	}
	return (1);
}

int	check_move_down1(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y + 1;
	x = game->minimap->pos_x;
	c = game->map->content[y][x];
	print_2d_arr(game->map->content);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].y += PLAYER_STEP;
		game->minimap->pos_y += PLAYER_STEP;
		return (0);
	}
	return (1);
}

int	check_move_left1(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y;
	x = game->minimap->pos_x - 1;
	c = game->map->content[y][x];
	print_2d_arr(game->map->content);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].x -= PLAYER_STEP;
		game->minimap->pos_x -= PLAYER_STEP;
		return (0);
	}
	return (1);

}

int	check_move_right1(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y;
	x = game->minimap->pos_x + 1;
	c = game->map->content[y][x];
	print_2d_arr(game->map->content);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].x += PLAYER_STEP;
		game->minimap->pos_x += PLAYER_STEP;
		return (0);
	}
	return (1);
}
