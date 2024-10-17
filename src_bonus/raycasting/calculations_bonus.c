/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:01:36 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/17 17:42:14 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	init_ray_info(t_ray_info *info, t_game *game, float angle, int is_hor)
{
	if (is_hor)
	{
		info->len_y = CELL;
		info->len_x = CELL / tan(angle);
		info->y = floor(game->player->y / CELL) * CELL;
		info->direction = get_h_drctn(angle, &info->y, &info->len_y);
		info->x = game->player->x + (info->y - game->player->y) / tan(angle);
		if (is_looking_west(angle) && info->len_x > 0)
			info->len_x *= -1;
		if (!is_looking_west(angle) && info->len_x < 0)
			info->len_x *= -1;
	}
	else
	{
		info->len_x = CELL;
		info->len_y = CELL * tan(angle);
		info->x = floor(game->player->x / CELL) * CELL;
		info->direction = get_v_drctn(angle, &info->x, &info->len_x);
		info->y = game->player->y + (info->x - game->player->x) * tan(angle);
		if (is_looking_south(angle) && info->len_y < 0)
			info->len_y *= -1;
		if (!is_looking_south(angle) && info->len_y > 0)
			info->len_y *= -1;
	}
}

int	is_hit(t_game *game, t_ray_info *info)
{
	if (info->map_x < 0 || info->map_y < 0
		|| info->map_x >= game->map->width || info->map_y >= game->map->height)
		return (1);
	info->cell = game->map->content[info->map_y][info->map_x];
	return (info->cell == '1'
		|| ((info->cell == 'V' || info->cell == 'H')
			&& !is_door_open(game, info->map_x, info->map_y)));
}

t_hit	cast_ray(t_game *game, float angle, int is_horizontal)
{
	t_hit		hit;
	t_ray_info	info;

	hit = (t_hit){INFINITY, 0, 0, 0};
	init_ray_info(&info, game, angle, is_horizontal);
	while (1)
	{
		update_map_coordinates(&info, is_horizontal);
		if (is_hit(game, &info))
		{
			hit.distance = calculate_len(game, info.x, info.y);
			hit.is_door = (info.cell == 'V' || info.cell == 'H');
			hit.x = info.x;
			hit.y = info.y;
			break ;
		}
		info.x += info.len_x;
		info.y += info.len_y;
	}
	return (hit);
}

float	get_len_to_wall(t_game *game, t_ray *ray)
{
	t_hit	h_hit;
	t_hit	v_hit;

	h_hit = cast_ray(game, ray->current_angle, 1);
	v_hit = cast_ray(game, ray->current_angle, 0);
	if (h_hit.distance < v_hit.distance)
	{
		ray->hit_door = h_hit.is_door;
		ray->wall_hit_x = h_hit.x;
		ray->wall_hit_y = h_hit.y;
		ray->horlen = h_hit.distance;
		ray->verlen = v_hit.distance;
		return (h_hit.distance);
	}
	else
	{
		ray->hit_door = v_hit.is_door;
		ray->wall_hit_x = v_hit.x;
		ray->wall_hit_y = v_hit.y;
		ray->horlen = h_hit.distance;
		ray->verlen = v_hit.distance;
		return (v_hit.distance);
	}
}

int	ray_calculation(t_game *game)
{
	t_ray	ray;

	ray.index = 0;
	ray.current_angle = game->player->angle - (((FOV * PI) / 180) / 2);
	while (ray.index < NUM_RAYS)
	{
		ray.current_angle = angle_check(ray.current_angle);
		ray.hit_door = 0;
		ray.len = get_len_to_wall(game, &ray);
		ray.len *= 0.4;
		rendering_wall(game, ray);
		ray.index++;
		ray.current_angle += (((FOV * PI) / 180) / WINDOW_WIDTH);
	}
	return (0);
}
