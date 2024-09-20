/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/20 12:30:16 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_move_up(t_game *game)
{
	int x;
	int y;
	x = game->minimap->pos_x;
	y = (game->minimap->image->instances[0].y - PLAYER_STEP) / PIXEL_MINI;
	if(DEBUG_COLLISION)
		printf("%c %i %i \n",game->map->map_as_arr[y][x], x,y);

	if('1' != game->map->map_as_arr[y][x] )
	{
		game->minimap->image->instances[0].y -= PLAYER_STEP;
		game->minimap->pos_y = y;
	}
	return (1);
}

int	check_move_down(t_game *game)
{
	int x;
	int y;
	x = game->minimap->pos_x;
	y = (game->minimap->image->instances[0].y + PIXEL_MINI_CHAR + PLAYER_STEP) / PIXEL_MINI;
	if(DEBUG_COLLISION)
		printf("%c %i %i \n",game->map->map_as_arr[y][x], x,y);
	if('1' != game->map->map_as_arr[y][x] )
	{
		game->minimap->image->instances[0].y += PLAYER_STEP;
		game->minimap->pos_y = y;
	}
	return (1);
}

int	check_move_left(t_game *game)
{
	int x;
	int y;
	x = (game->minimap->image->instances[0].x - PLAYER_STEP) / PIXEL_MINI;
	y = game->minimap->pos_y;
	if(DEBUG_COLLISION)
		printf("%c %i %i \n",game->map->map_as_arr[y][x], x,y);
	if('1' != game->map->map_as_arr[y][x] )
	{
		game->minimap->image->instances[0].x -= PLAYER_STEP;
		game->minimap->pos_x = x;
	}
	return (1);
}

int	check_move_right(t_game *game)
{
	int x;
	int y;
	x = (game->minimap->image->instances[0].x + PIXEL_MINI_CHAR + PLAYER_STEP) / PIXEL_MINI;
	y = game->minimap->pos_y;
	if(DEBUG_COLLISION)
		printf("%c %i %i \n",game->map->map_as_arr[y][x], x,y);
	if('1' != game->map->map_as_arr[y][x] )
	{
		game->minimap->image->instances[0].x += PLAYER_STEP;
		game->minimap->pos_x = x;
	}

	return (1);
}
