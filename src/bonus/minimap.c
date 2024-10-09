/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:17:54 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/09 18:24:18 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	mclear_and_draw_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_FRAME)
	{
		x = 0;
		while (x < MAP_FRAME)
		{
			if (x < FRAME_THICKNESS || x >= MAP_FRAME - FRAME_THICKNESS
				|| y < FRAME_THICKNESS || y >= MAP_FRAME - FRAME_THICKNESS)
			{
				mlx_put_pixel(game->surface, x, y, FRAME_COLOR);
			}
			else
			{
				mlx_put_pixel(game->surface, x, y, WALL_COLOR);
			}
			x++;
		}
		y++;
	}
}

void	mrender_rotmap(t_game *game, float cos_angle, float sin_angle)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	float	rot_x;
	float	rot_y;

	y = FRAME_THICKNESS;
	while (y < MAP_FRAME - FRAME_THICKNESS)
	{
		x = FRAME_THICKNESS;
		while (x < MAP_FRAME - FRAME_THICKNESS)
		{
			rot_x = -(y - (MAP_FRAME / 2)) * cos_angle + (x - (MAP_FRAME / 2)) * sin_angle;
			rot_y = (y - (MAP_FRAME / 2)) * sin_angle + (x - (MAP_FRAME / 2)) * cos_angle;
			map_x = (int)((game->player->x / CELL) + (rot_x / (float)MCELL));
			map_y = (int)((game->player->y / CELL) + (rot_y / (float)MCELL));
			if (map_x >= 0 && map_x < game->map->width && map_y >= 0 && map_y < game->map->height)
			{
				if (game->map->content[map_y][map_x] == '1')
					mlx_put_pixel(game->surface, x, y, WALL_COLOR);
				else if (ft_strchr("NEWS0", game->map->content[map_y][map_x]))
					mlx_put_pixel(game->surface, x, y, ROOM_COLOR);
			}
			x++;
		}
		y++;
	}
}

void mdraw_rays(t_game *game, float cos_angle, float sin_angle)
{
	float ray_angle = game->player->angle - (PI / 4);
	int i = 0;

	while (i < NUM_RAYS)
	{
		float sin_a = sin(ray_angle);
		float cos_a = cos(ray_angle);
		float ray_x = game->player->x;
		float ray_y = game->player->y;
		while (1)
		{
			ray_x += cos_a;
			ray_y += sin_a;

			int map_ray_x = (int)(ray_x / CELL);
			int map_ray_y = (int)(ray_y / CELL);

			if (map_ray_x < 0 || map_ray_x >= game->map->width || map_ray_y < 0 || map_ray_y >= game->map->height || game->map->content[map_ray_y][map_ray_x] == '1')
			{
				break;
			}
			float rel_x = ray_x - game->player->x;
			float rel_y = ray_y - game->player->y;
			float rot_ray_x = rel_x * cos_angle - rel_y * sin_angle;
			float rot_ray_y = rel_x * sin_angle + rel_y * cos_angle;
			float display_x = rot_ray_y;
			float display_y = -rot_ray_x;
			int minimap_x = MAP_FRAME / 2 + (int)(display_x * MCELL / CELL);
			int minimap_y = MAP_FRAME / 2 + (int)(display_y * MCELL / CELL);
			if (minimap_x >= FRAME_THICKNESS && minimap_x < MAP_FRAME - FRAME_THICKNESS &&
				minimap_y >= FRAME_THICKNESS && minimap_y < MAP_FRAME - FRAME_THICKNESS)
			{
				mlx_put_pixel(game->surface, minimap_x, minimap_y, RAY_COLOR);
			}
		}
		ray_angle += (PI / 2) / NUM_RAYS;
		i++;
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
			px = (MAP_FRAME / 2) + x;
			py = (MAP_FRAME / 2) + y;
			if (px >= FRAME_THICKNESS && px < MAP_FRAME - FRAME_THICKNESS
				&& py >= FRAME_THICKNESS && py < MAP_FRAME - FRAME_THICKNESS)
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
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(-game->player->angle);
	sin_angle = sin(-game->player->angle);
	mclear_and_draw_frame(game);
	mrender_rotmap(game, cos_angle, sin_angle);
	mrender_rotmap(game, cos_angle, sin_angle);
	mdraw_rays(game, cos_angle, sin_angle);
	mdraw_player(game);
}
