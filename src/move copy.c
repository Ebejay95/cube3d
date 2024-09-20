/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 15:19:50 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_move_up(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y + 1;
	x = game->minimap->pos_x;
	c = game->map->map_as_arr[y][x];
	print_2d_arr(game->map->map_as_arr);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].y -= PLAYER_STEP;
		game->minimap->pos_y -= PLAYER_STEP;
		return (0);
	}
	return (1);
}

int	check_move_down(t_game *game)
{
	char	c;
	int		y;
	int		x;

	printf("HERERERERERERERRE\n");
	y = game->minimap->pos_y + 1;
	x = game->minimap->pos_x;
	c = game->map->map_as_arr[y][x];
	print_2d_arr(game->map->map_as_arr);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].y += PLAYER_STEP;
		game->minimap->pos_y += PLAYER_STEP;
		return (0);
	}
	return (1);
}

int	check_move_left(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y;
	x = game->minimap->pos_x - 1;
	c = game->map->map_as_arr[y][x];
	print_2d_arr(game->map->map_as_arr);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].x -= PLAYER_STEP;
		game->minimap->pos_x -= PLAYER_STEP;
		return (0);
	}
	return (1);

}

int	check_move_right(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = game->minimap->pos_y;
	x = game->minimap->pos_x + 1;
	c = game->map->map_as_arr[y][x];
	print_2d_arr(game->map->map_as_arr);
	printf("[X%i] [Y%i] [C%c]\n",x,y,c);
	if (c != '1')
	{
		game->minimap->image->instances[0].x += PLAYER_STEP;
		game->minimap->pos_x += PLAYER_STEP;
		return (0);
	}
	return (1);
}
