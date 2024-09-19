/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 14:03:25 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_move_up(t_game *game)
{

	game->minimap->image->instances[0].y -= PLAYER_STEP;
	return (1);
}

int	check_move_down(t_game *game)
{

	game->minimap->image->instances[0].y += PLAYER_STEP;
	return (1);
}

int	check_move_left(t_game *game)
{

	game->minimap->image->instances[0].x -= PLAYER_STEP;
	return (1);

}

int	check_move_right(t_game *game)
{

	game->minimap->image->instances[0].x += PLAYER_STEP;
	return (1);
}
