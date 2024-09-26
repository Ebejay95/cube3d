/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:06:42 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/26 12:07:04 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_ray_data(t_game *game, t_ray_data *ray)
{
	ray->posx = game->player->x;
	ray->posy = game->player->y;
	ray->dirx = game->minimap->deltax;
	ray->diry = game->minimap->deltay;
	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->hit = 0;
}

void	calculate_step_and_sidedist(t_ray_data *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

void	perform_dda(t_game *game, t_ray_data *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
		}
		if (get_cellchar(game, ray->mapx, ray->mapy) == '1')
			ray->hit = 1;
	}
}


void	dda_raycast(t_game *game, int *hitx, int *hity)
{
	t_ray_data	ray;

	initialize_ray_data(game, &ray);
	calculate_step_and_sidedist(&ray);
	perform_dda(game, &ray);
	*hitx = ray.mapx;
	*hity = ray.mapy;
}
