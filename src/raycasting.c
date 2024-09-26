/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:24:34 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/26 14:48:51 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"




void	rendering(t_game *game, int hitx, int hity, float angle, int x)
{
	int lenx = hitx - game->player->x;
	int leny = hity - game->player->y;
	float rend_len;
	float len = sqrt((pow(abs(lenx), 2)) + (pow(abs(leny), 2)));
	rend_len = fabs(len * cos(to_radian(180 - angle)));
	float start_height = WINDOW_HEIGHT / 2 - BLOCK_HEIGHT / rend_len;
	float end_height = WINDOW_HEIGHT / 2 + BLOCK_HEIGHT / rend_len;
	int	y = start_height;
	while (y < end_height)
	{
		draw_pixel(game->surface , x, y, WALL_COLOR2);
		y++;
	}
}



int	render_game(t_game *game)
{
	float	start_angle;
	float	current_angle;
	int		i;
	int		hitx;
	int		hity;
	i = 0;


	start_angle = game->player->angle - (FOV / 2);
	float	angle_begin = -45.0;
	while (i <= NUM_RAYS)
	{
		current_angle = start_angle + i * RAY_ANGLE_STEP;
		current_angle = angle_check(current_angle);
		game->deltax = cos(current_angle);
		game->deltay = sin(current_angle);
		dda_raycast(game, &hitx, &hity);
		i++;
		angle_begin += (90.0f / (float)NUM_RAYS);
		rendering(game, hitx, hity, angle_begin, i);

	}
	return (0);
}
