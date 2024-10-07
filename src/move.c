/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/07 15:00:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	i_like_to_move_it_move_it(t_game *game, float new_x, float new_y)
{
	game->player->x = new_x;
	game->player->y = new_y;
}

int	check_move_up(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->x + cos(game->player->angle) * PLYR_STEP;
	new_y = game->player->y + sin(game->player->angle) * PLYR_STEP;
	check_collision(game, &new_x, &new_y);
	i_like_to_move_it_move_it(game, new_x, new_y);
	return (1);
}

int	check_move_down(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->x - cos(game->player->angle) * PLYR_STEP;
	new_y = game->player->y - sin(game->player->angle) * PLYR_STEP;
	check_collision(game, &new_x, &new_y);
	i_like_to_move_it_move_it(game, new_x, new_y);
	return (1);
}

int	check_move_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->x + sin(game->player->angle) * PLYR_STEP;
	new_y = game->player->y - cos(game->player->angle) * PLYR_STEP;
	check_collision(game, &new_x, &new_y);
	i_like_to_move_it_move_it(game, new_x, new_y);
	return (1);
}

int	check_move_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player->x - sin(game->player->angle) * PLYR_STEP;
	new_y = game->player->y + cos(game->player->angle) * PLYR_STEP;
	check_collision(game, &new_x, &new_y);
	i_like_to_move_it_move_it(game, new_x, new_y);
	return (1);
}
