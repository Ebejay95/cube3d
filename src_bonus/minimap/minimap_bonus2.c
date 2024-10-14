/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:41:08 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 22:08:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	handle_door(t_game *game, t_render_data *d)
{
	t_door	*door;

	door = get_door(game->map, d->map_x, d->map_y);
	if (door)
	{
		if (door->open)
			mlx_put_pixel(game->surface, d->x, d->y, DOOR_COLOR);
		else
			mlx_put_pixel(game->surface, d->x, d->y, DOOR_C_CLR);
	}
	else
		mlx_put_pixel(game->surface, d->x, d->y, ROOM_COLOR);
}

void	handle_room(t_game *game, t_render_data *d)
{
	mlx_put_pixel(game->surface, d->x, d->y, ROOM_COLOR);
}

void	process_map_content(t_game *game, t_render_data *d)
{
	char	map_content;

	map_content = game->map->content[d->map_y][d->map_x];
	if (map_content == '1')
		handle_wall(game, d);
	else if (map_content == 'V' || map_content == 'H')
		handle_door(game, d);
	else if (ft_strchr("NEWS0", map_content))
		handle_room(game, d);
}

void	process_column(t_game *game, t_render_data *d)
{
	d->x = FRAME_THICKNESS;
	while (d->x < MF - FRAME_THICKNESS)
	{
		calculate_map_coordinates(game, d);
		if (is_valid_map_position(game, d))
		{
			process_map_content(game, d);
		}
		d->x++;
	}
}

void	mrender_rotmap(t_game *game, float cosa, float sina)
{
	t_render_data	d;

	d.cosa = cosa;
	d.sina = sina;
	d.y = FRAME_THICKNESS;
	while (d.y < MF - FRAME_THICKNESS)
	{
		process_column(game, &d);
		d.y++;
	}
}
