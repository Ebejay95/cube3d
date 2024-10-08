/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:04:11 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/08 12:20:39 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void animation(void *param)
{
	t_game	*game;
 	// uint32_t alpha;

	game = (t_game *)param;
	// alpha = game->map->ceiling & 0xFF;
	// printf("%u %i\n", alpha, game->map->ceiling);
	game->frame_bonus += 1;
	if(game->frame_bonus == FRAME * 1)
	{

	}
	if(game->frame_bonus == FRAME * 2)
	{
		game->frame_bonus = 0;
	}
}
