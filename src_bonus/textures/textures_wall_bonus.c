/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_wall_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:58:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/09 23:58:49 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

// int	ft_load_textures_item(t_game *game)
// {
// 	int	i;
// 	int	pos_y;
// 	int	pos_x;

// 	i = 0;
// 	while (i < game->item_total)
// 	{
// 		game->item[i]->texture = mlx_load_png(PATH_ITEM);
// 		if (!game->item[i]->texture)
// 			return (call_exit(game), 0);
// 		game->item[i]->image = mlx_texture_to_image(game->game_window,
// 				game->item[i]->texture);
// 		if (!game->item[i]->image)
// 			return (call_exit(game), 0);
// 		pos_y = game->item[i]->pos->y * PIXEL;
// 		pos_x = game->item[i]->pos->x * PIXEL;
// 		if (mlx_image_to_window(game->game_window, game->item[i]->image, pos_x,
// 				pos_y) == -1)
// 			return (call_exit(game), 0);
// 		mlx_delete_texture(game->item[i]->texture);
// 		i++;
// 	}
// 	return (0);
// }
