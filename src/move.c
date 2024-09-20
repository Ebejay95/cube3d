/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 16:22:17 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_move_up(t_game *game)
{
	if(game->minimap->image->instances[0].y - PLAYER_STEP >= PIXEL_MINI)
	{
		// printf("---------->X:%i Y:%i\n",((((game->minimap->image->instances[0].x + PLAYER_STEP) + (PIXEL_MINI / 2)) / (PIXEL / 2)) + 1), ((((game->minimap->image->instances[0].y + PLAYER_STEP) + (PIXEL_MINI / 2)) / (PIXEL / 2)) + 1);
		// if(game->map->map_as_arr[game->minimap->pos_x][((game->minimap->pos_y - PLAYER_STEP) * PIXEL_MINI) / 32] != '1')
		// {
			// printf("											[%i][%i]\n",game->minimap->pos_x, (((game->minimap->pos_y - PLAYER_STEP) * PIXEL_MINI) / 32));
			game->minimap->image->instances[0].y -= PLAYER_STEP;
			game->minimap->pos_y -= PLAYER_STEP;
		// }
	}
	return (1);
}

int	check_move_down(t_game *game)
{
	if(game->minimap->image->instances[0].y + PLAYER_STEP <= ((PIXEL_MINI * 8) - (PIXEL_MINI / 2)))
	{
		printf("---------->X:%i Y:%i\n",((game->minimap->image->instances[0].x + PLAYER_STEP + (PIXEL_MINI / 2)) / (PIXEL / 2) + 1), (game->minimap->image->instances[0].y + PLAYER_STEP + (PIXEL_MINI / 2)) / (PIXEL / 2) + 1);
		// if(game->map->map_as_arr[game->minimap->pos_x][((game->minimap->pos_y + PLAYER_STEP) * PIXEL_MINI) / 32] != '1')
		// {
			// printf("											[%i][%i]\n",game->minimap->pos_x, (((game->minimap->pos_y + PLAYER_STEP) * PIXEL_MINI) / 32));
			game->minimap->image->instances[0].y += PLAYER_STEP;
			game->minimap->pos_y += PLAYER_STEP;
		// }
	}

	return (1);
}

int	check_move_left(t_game *game)
{
	if(game->minimap->image->instances[0].x - PLAYER_STEP >= PIXEL_MINI)
	{
		printf("---------->X:%i Y:%i\n",((game->minimap->image->instances[0].x + PLAYER_STEP + (PIXEL_MINI / 2)) / (PIXEL / 2) + 1), (game->minimap->image->instances[0].y + PLAYER_STEP + (PIXEL_MINI / 2)) / (PIXEL / 2) + 1);
		// if(game->map->map_as_arr[((game->minimap->pos_x - PLAYER_STEP) * PIXEL_MINI) / 32][game->minimap->pos_y] != '1')
		// {
			// printf("											[%i][%i]\n",(((game->minimap->pos_x - PLAYER_STEP) * PIXEL_MINI) / 32), game->minimap->pos_y);
			game->minimap->image->instances[0].x -= PLAYER_STEP;
			game->minimap->pos_x -= PLAYER_STEP;
		// }
	}
	return (1);

}

int	check_move_right(t_game *game)
{

	if(game->minimap->image->instances[0].x + PLAYER_STEP <= ((PIXEL_MINI * 9) - (PIXEL_MINI / 2)))
	{
		printf("---------->X:%i Y:%i\n",((game->minimap->image->instances[0].x + PLAYER_STEP + (PIXEL_MINI / 2)) / (PIXEL / 2) + 1), (game->minimap->image->instances[0].y + PLAYER_STEP + (PIXEL_MINI / 2)) / (PIXEL / 2) + 1);
		// if(game->map->map_as_arr[((game->minimap->pos_x + PLAYER_STEP) * PIXEL_MINI) / 32][game->minimap->pos_y] != '1')
		// {
			// printf("											[%i][%i]\n",(((game->minimap->pos_x + PLAYER_STEP) * PIXEL_MINI) / 32), game->minimap->pos_y);
			game->minimap->image->instances[0].x += PLAYER_STEP;
			game->minimap->pos_x += PLAYER_STEP;
		// }
	}
	return (1);
}
