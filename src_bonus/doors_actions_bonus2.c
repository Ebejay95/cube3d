/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_actions_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:41:00 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 20:41:27 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"

void	init_ray(t_game *game, t_dctx *ray)
{
	ray->x = game->player->x;
	ray->y = game->player->y;
	ray->sin_a = sin(ray->angle);
	ray->cos_a = cos(ray->angle);
}

void	update_ray_position(t_dctx *ray)
{
	ray->x += ray->cos_a;
	ray->y += ray->sin_a;
	ray->map_x = (int)(ray->x / CELL);
	ray->map_y = (int)(ray->y / CELL);
}
