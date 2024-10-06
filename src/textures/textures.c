/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:08:29 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/06 12:45:26 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int	init_walls(t_game *game)
{
	game->map->img_north = mlx_texture_to_image(game->mlx, game->map->tex_north);
	if(!game->map->img_north)
		return(1);
	if (mlx_image_to_window(game->mlx, game->map->img_north, 0,	0) == -1)
		return(1);
	int	i = 0;
	while(game->map->tex_north->pixels[i])
	{
		uint32_t color = get_rgba_colors_hex(game->map->tex_north->pixels[i],game->map->tex_north->pixels[i + 1],game->map->tex_north->pixels[i + 2],game->map->tex_north->pixels[i+3]);
		printf("%i %u\n ",i, color);
		i += 4;
	}
	printf("\n");

	return(0);
}

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	// calc_delta(game, ' ');
	// i += ft_load_textures_minimap(game);

	i += init_walls(game);
	printf("END\n");


	if (i)
		return (call_exit(game), 1);
	return (i);
}
