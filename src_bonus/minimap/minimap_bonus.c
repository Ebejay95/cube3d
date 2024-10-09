/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:08:08 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/10 00:08:13 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	calculate_map_coordinates(t_game *game, t_render_data *d)
{
	d->rot_x = -(d->y - (MF / 2)) * d->cosa + (d->x - (MF / 2)) * d->sina;
	d->rot_y = (d->y - (MF / 2)) * d->sina + (d->x - (MF / 2)) * d->cosa;
	d->map_x = (int)((game->player->x / CELL) + (d->rot_x / (float)MCELL));
	d->map_y = (int)((game->player->y / CELL) + (d->rot_y / (float)MCELL));
}

int	is_valid_map_position(t_game *game, t_render_data *d)
{
	if (d->map_x >= 0 && d->map_x < game->map->width && d->map_y >= 0
		&& d->map_y < game->map->height)
		return (1);
	return (0);
}

void	mrender_rotmap(t_game *game, float cosa, float sina)
{
	t_render_data	data;
	char			map_content;

	data.cosa = cosa;
	data.sina = sina;
	data.y = FRAME_THICKNESS;
	while (data.y < MF - FRAME_THICKNESS)
	{
		data.x = FRAME_THICKNESS;
		while (data.x < MF - FRAME_THICKNESS)
		{
			calculate_map_coordinates(game, &data);
			if (is_valid_map_position(game, &data))
			{
				map_content = game->map->content[data.map_y][data.map_x];
				if (map_content == '1')
					mlx_put_pixel(game->surface, data.x, data.y, WALL_COLOR);
				else if (ft_strchr("NEWS0", map_content))
					mlx_put_pixel(game->surface, data.x, data.y, ROOM_COLOR);
			}
			data.x++;
		}
		data.y++;
	}
}

void	mdraw_player(t_game *game)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = -2;
	while (y <= 2)
	{
		x = -2;
		while (x <= 2)
		{
			px = (MF / 2) + x;
			py = (MF / 2) + y;
			if (px >= FRAME_THICKNESS && px < MF - FRAME_THICKNESS
				&& py >= FRAME_THICKNESS && py < MF - FRAME_THICKNESS)
			{
				mlx_put_pixel(game->surface, px, py, PLAYER_COLOR);
			}
			x++;
		}
		y++;
	}
}

void	render_minimap(t_game *game)
{
	float	cosa;
	float	sina;
	int		x;
	int		y;

	cosa = cos(-game->player->angle);
	sina = sin(-game->player->angle);
	y = 0;
	while (y < MF)
	{
		x = 0;
		while (x < MF)
		{
			if (x < FRAME_THICKNESS || x >= MF - FRAME_THICKNESS
				|| y < FRAME_THICKNESS || y >= MF - FRAME_THICKNESS)
				mlx_put_pixel(game->surface, x, y, FRAME_COLOR);
			else
				mlx_put_pixel(game->surface, x, y, WALL_COLOR);
			x++;
		}
		y++;
	}
	mrender_rotmap(game, cosa, sina);
	mrender_rotmap(game, cosa, sina);
	mdraw_player(game);
}
