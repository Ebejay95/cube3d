/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:21:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/27 15:03:43 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"



// Dimension of the Projection Plane = 320 x 200 units
// Center of the Projection Plane = (160,100)
// Distance to the Projection Plane = 277 units
// Angle between subsequent rays = 60/320 degrees


//    If the ray is facing up
//      A.y = rounded_down(Py/64) * (64) - 1;
//    If the ray is facing down
//      A.y = rounded_down(Py/64) * (64) + 64;
// A.x = Px + (Py-A.y)/tan(ALPHA);
//    In the picture, (assume ALPHA is 60 degrees),
//    A.x=96 + (224-191)/tan(60) = about 115;
//    The grid coordinate of A.x is 115/64 = 1;
float find_horizontal(t_game* game)
{
	float horizontal;
	float vertical;


	if(game->player->angle >= PI)
		horizontal = ((game->player->y / CELL) * (64 - 1));
	else
		horizontal = ((game->player->y / CELL) * (64) + 64);

	vertical = game->player->x + (game->player->y - horizontal) / tan(game->player->angle);

	printf("X%f Y%f A%f H%f V%f\n", game->player->x, game->player->y, game->player->angle, horizontal, vertical);
	mlx_put_pixel(game->surface, vertical , horizontal , PLAYER_COLOR); // Choose a color for the grid lines

	return horizontal;


	// return vertical;
}


// float find_vertical(t_game* game)
// {
// }

int	render(t_game* game)
{
	float horizontal;
	// float vertical;

	horizontal = find_horizontal(game);
	// vertical = find_vertical(game);
	return(0);
}
