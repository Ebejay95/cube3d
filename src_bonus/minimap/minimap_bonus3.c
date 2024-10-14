/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:09:13 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 22:09:24 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

void	handle_wall(t_game *game, t_render_data *d)
{
	mlx_put_pixel(game->surface, d->x, d->y, WALL_COLOR);
}
