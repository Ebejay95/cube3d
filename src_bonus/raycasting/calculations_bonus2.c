/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_bonus2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:39:59 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/17 17:42:29 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	update_map_coordinates(t_ray_info *info, int is_horizontal)
{
	if (is_horizontal)
	{
		info->map_y = (int)((info->y - info->direction) / CELL);
		info->map_x = (int)(info->x / CELL);
	}
	else
	{
		info->map_y = (int)(info->y / CELL);
		info->map_x = (int)((info->x - info->direction) / CELL);
	}
}
