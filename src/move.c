/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/20 12:12:47 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_move_up(t_game *game)
{
	if(DEBUG_COLLISION)
	{
		char c = game->map->map_as_arr[game->minimap->pos_x][(game->minimap->image->instances[0].y - PLAYER_STEP) / PIXEL_MINI];
		int x = game->minimap->pos_x;
		int y = (game->minimap->image->instances[0].y - PLAYER_STEP) / PIXEL_MINI;
		printf("%c %i %i \n",c, x,y);
	}
	if('1' != game->map->map_as_arr[game->minimap->pos_x][(game->minimap->image->instances[0].y - PLAYER_STEP) / PIXEL_MINI] )
	{
		game->minimap->image->instances[0].y -= PLAYER_STEP;
		game->minimap->pos_y = game->minimap->image->instances[0].y / PIXEL_MINI;
	}
	return (1);
}

int	check_move_down(t_game *game)
{
	if(DEBUG_COLLISION)
	{
		char c = game->map->map_as_arr[game->minimap->pos_x][(game->minimap->image->instances[0].y + PIXEL_MINI_CHAR + PLAYER_STEP) / PIXEL_MINI];
		int x = game->minimap->pos_x;
		int y = (game->minimap->image->instances[0].y + PIXEL_MINI_CHAR + PLAYER_STEP) / PIXEL_MINI;
		printf("%c %i %i \n",c, x,y);
	}
	if('1' != game->map->map_as_arr[game->minimap->pos_x][(game->minimap->image->instances[0].y + PIXEL_MINI_CHAR + PLAYER_STEP) / PIXEL_MINI] )
	{
		game->minimap->image->instances[0].y += PLAYER_STEP;
		game->minimap->pos_y = (game->minimap->image->instances[0].y + PIXEL_MINI_CHAR + PLAYER_STEP) / PIXEL_MINI;
	}
	return (1);
}

int	check_move_left(t_game *game)
{
	if(DEBUG_COLLISION)
	{
		char c = game->map->map_as_arr[(game->minimap->image->instances[0].x - PLAYER_STEP) / PIXEL_MINI][game->minimap->pos_y];
		int x = (game->minimap->image->instances[0].x - PLAYER_STEP) / PIXEL_MINI;
		int y = game->minimap->pos_y;
		printf("%c %i %i \n",c, x,y);
	}
	if('1' != game->map->map_as_arr[(game->minimap->image->instances[0].x - PLAYER_STEP) / PIXEL_MINI][game->minimap->pos_y] )
	{
		game->minimap->image->instances[0].x -= PLAYER_STEP;
		game->minimap->pos_x = game->minimap->image->instances[0].x / PIXEL_MINI;
	}
	return (1);
}

int	check_move_right(t_game *game)
{
	if(DEBUG_COLLISION)
	{
		char c = game->map->map_as_arr[(game->minimap->image->instances[0].x + PIXEL_MINI_CHAR + PLAYER_STEP - 1) / PIXEL_MINI][game->minimap->pos_y];
		int x = (game->minimap->image->instances[0].x + PIXEL_MINI_CHAR + PLAYER_STEP - 1) / PIXEL_MINI;
		int y = game->minimap->pos_y;
		printf("%c %i %i \n",c, x,y);
	}
	if('1' != game->map->map_as_arr[(game->minimap->image->instances[0].x + PIXEL_MINI_CHAR + PLAYER_STEP - 1) / PIXEL_MINI][game->minimap->pos_y] )
	{
		game->minimap->image->instances[0].x += PLAYER_STEP;
		game->minimap->pos_x = (game->minimap->image->instances[0].x + PIXEL_MINI_CHAR + PLAYER_STEP - 1) / PIXEL_MINI;
	}

	return (1);
}
